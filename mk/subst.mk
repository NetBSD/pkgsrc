# $NetBSD: subst.mk,v 1.67 2020/03/21 13:30:35 rillig Exp $
#
# The subst framework replaces text in one or more files in the WRKSRC
# directory. Packages can define several ``classes'' of replacements.
# Each such class defines:
#
#	- in which stage of the build process the replacement happens
#	- which files are affected by the replacement
#	- which text or pattern is replaced by which replacement text
#
# A typical example is:
#
#	SUBST_CLASSES+=		prefix
#	SUBST_STAGE.prefix=	pre-configure
#	SUBST_FILES.prefix=	./configure doc/*.html
#	SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},g'
#
# User-settable variables:
#
# SUBST_SHOW_DIFF
#	Whether to log each changed file as a unified diff, for all
#	SUBST classes. Defaults to "no".
#
# Package-settable variables:
#
# SUBST_CLASSES
#	A list of class names.  When adding new classes to this list, be
#	sure to append them (+=) instead of overriding them (=).
#
# SUBST_STAGE.<class>
#	"stage" at which we do the text replacement. Should be one of
#	{pre,do,post}-{extract,patch,configure,build,install}.
#
# SUBST_MESSAGE.<class>
#	The message to display before doing the substitution.
#
# SUBST_FILES.<class>
#	A list of file patterns on which to run the substitution;
#	the filenames are either absolute or relative to ${WRKSRC}.
#
#	Starting with 2020Q1, it is an error if any of these patterns
#	has no effect at all, to catch typos and outdated definitions.
#	To prevent this, see SUBST_NOOP_OK.<class> below.
#
#	In most cases the filename patterns are given directly.
#	If that is not flexible enough, use the :sh variable modifier.
#	See mk/configure/replace-localedir.mk for an example.
#
# SUBST_SED.<class>
#	List of sed(1) arguments to run on the specified files.
#	Multiple commands can be specified using the -e option of sed.
#	Do not use non-standard sed options (e.g. -E).
#
# SUBST_VARS.<class>
#	List of variables that are substituted whenever they appear in
#	the form @VARNAME@. This is basically a shortcut for
#
#		-e 's,@VARNAME@,${VARNAME},g'
#
#	that even works when ${VARNAME} contains arbitrary characters.
#	SUBST_SED and SUBST_VARS can combined freely.
#
# SUBST_FILTER_CMD.<class>
#	Filter used to perform the actual substitution on the specified
#	files.  Defaults to ${SED} ${SUBST_SED.<class>}.
#
# SUBST_SKIP_TEXT_CHECK.<class>
#	By default, each file is checked whether it really is a text file
#	before any substitutions are done to it. Since that test is not
#	perfect, it can be disabled by setting this variable to "yes".
#
# SUBST_SHOW_DIFF.<class>
#	During development of a package, this can be set to "yes" to see
#	the actual changes as a unified diff.
#
# SUBST_NOOP_OK.<class>
#	Whether to fail when a SUBST_FILES pattern has no effect.
#	In most cases, "yes" is appropriate, to catch typos and outdated
#	definitions.
#
#	Default: no (up to 2019Q4), yes (starting with 2020Q1)
#
# See also:
#	PLIST_SUBST
#
# Keywords: subst
#

_VARGROUPS+=		subst
_PKG_VARS.subst=	SUBST_CLASSES
SUBST_SHOW_DIFF?=	no
.for c in ${SUBST_CLASSES}
.  for pv in SUBST_STAGE SUBST_MESSAGE SUBST_FILES SUBST_SED SUBST_VARS	\
	SUBST_FILTER_CMD SUBST_SKIP_TEXT_CHECK SUBST_NOOP_OK
_PKG_VARS.subst+=	${pv}.${c}
.  endfor
.endfor
_DEF_VARS.subst=	ECHO_SUBST_MSG
_USE_VARS.subst=	WRKDIR WRKSRC
_IGN_VARS.subst=	_SUBST_IS_TEXT_FILE_CMD
_SORTED_VARS.subst=	SUBST_CLASSES SUBST_FILES.* SUBST_VARS.*
_LISTED_VARS.subst=	SUBST_SED.* SUBST_FILTER_CMD.*

ECHO_SUBST_MSG?=	${STEP_MSG}

# _SUBST_IS_TEXT_FILE_CMD returns 0 if $$file is a text file.
_SUBST_IS_TEXT_FILE_CMD?= \
	[ -z "`LC_ALL=C ${TR} -cd '\\0' < "$$file" | ${TR} '\\0' 'x'`" ]

.if ${SUBST_CLASSES:U:O} != ${SUBST_CLASSES:U:O:u}
PKG_FAIL_REASON+=	"[subst.mk] duplicate SUBST class in: ${SUBST_CLASSES:O}"
.endif

.for _class_ in ${SUBST_CLASSES:O:u}
_SUBST_COOKIE.${_class_}=	${WRKDIR}/.subst_${_class_}_done

SUBST_FILTER_CMD.${_class_}?=	LC_ALL=C ${SED} ${SUBST_SED.${_class_}}
SUBST_VARS.${_class_}?=		# none
SUBST_MESSAGE.${_class_}?=	Substituting "${_class_}" in ${SUBST_FILES.${_class_}}
.  for v in ${SUBST_VARS.${_class_}}
SUBST_FILTER_CMD.${_class_}+=	-e s,@${v:C|[^A-Za-z0-9_]|\\\\&|gW:Q}@,${${v}:S|\\|\\\\|gW:S|,|\\,|gW:S|&|\\\&|gW:S|${.newline}|\\${.newline}|gW:Q},g
.  endfor
.  if ${SUBST_SHOW_DIFF.${_class_}:U${SUBST_SHOW_DIFF}:tl} == yes
_SUBST_KEEP.${_class_}?=	${DIFF} -u "$$file" "$$tmpfile" || true
.  endif
_SUBST_KEEP.${_class_}?=	${DO_NADA}
SUBST_SKIP_TEXT_CHECK.${_class_}?=	no
SUBST_NOOP_OK.${_class_}?=	yes # TODO: change to no after 2020Q1

.if !empty(SUBST_SKIP_TEXT_CHECK.${_class_}:M[Yy][Ee][Ss])
_SUBST_IS_TEXT_FILE_CMD.${_class_}=	${TRUE}
.else
_SUBST_IS_TEXT_FILE_CMD.${_class_}=	${_SUBST_IS_TEXT_FILE_CMD}
.endif

.  if defined(SUBST_STAGE.${_class_})
${SUBST_STAGE.${_class_}}: subst-${_class_}
.  else
# SUBST_STAGE.* does not need to be defined.
#PKG_FAIL_REASON+=	"SUBST_STAGE missing for ${_class_}."
.  endif

.PHONY: subst-${_class_}
subst-${_class_}: ${_SUBST_COOKIE.${_class_}}

${_SUBST_COOKIE.${_class_}}:
	${RUN} message=${SUBST_MESSAGE.${_class_}:Q};			\
	if [ "$$message" ]; then ${ECHO_SUBST_MSG} "$$message"; fi
	${RUN}								\
	basedir=${WRKSRC:Q};						\
	emptydir="$$basedir/.subst-empty";				\
	patterns=${SUBST_FILES.${_class_}:Q};				\
	${MKDIR} "$$emptydir"; cd "$$emptydir";				\
	for pattern in $$patterns; do					\
	changed=no;							\
	cd "$$basedir";							\
	for file in $$pattern; do					\
		case $$file in /*) ;; *) file="./$$file";; esac;	\
		tmpfile="$$file.subst.sav";				\
		if [ ! -f "$$file" ]; then				\
			${WARNING_MSG} "[subst.mk:${_class_}] Ignoring non-existent file \"$$file\"."; \
		elif ${_SUBST_IS_TEXT_FILE_CMD.${_class_}}; then	\
			${SUBST_FILTER_CMD.${_class_}}			\
			< "$$file"					\
			> "$$tmpfile";					\
			if ${TEST} -x "$$file"; then			\
				${CHMOD} +x "$$tmpfile";		\
			fi;						\
			if ${CMP} -s "$$tmpfile" "$$file"; then 	\
				${INFO_MSG} "[subst.mk:${_class_}] Nothing changed in $$file."; \
				${RM} -f "$$tmpfile";			\
			else						\
				changed=yes;				\
				${_SUBST_KEEP.${_class_}};		\
				${MV} -f "$$tmpfile" "$$file"; 		\
				${ECHO} "$$file" >> ${.TARGET};		\
			fi;						\
		else							\
			${WARNING_MSG} "[subst.mk:${_class_}] Ignoring non-text file \"$$file\"."; \
		fi;							\
	done;								\
	\
	if test "$$changed,${SUBST_NOOP_OK.${_class_}:tl}" = no,no; then \
		${FAIL_MSG} "[subst.mk:${_class_}] The pattern $$pattern has no effect."; \
	fi; \
	done; \
	${RMDIR} "$$emptydir"
	${RUN} ${TOUCH} ${TOUCH_FLAGS} ${.TARGET:Q}
.endfor
