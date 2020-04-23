# $NetBSD: subst.mk,v 1.82 2020/04/23 19:16:49 rillig Exp $
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
# SUBST_NOOP_OK
#	Whether it is ok to have filename patterns in SUBST_FILES that
#	don't have any effect.
#
#	For backwards compatibility this defaults to "yes", but it
#	should rather be set to "no".
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
#	SUBST_SED and SUBST_VARS can be combined freely.
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

SUBST_SHOW_DIFF?=	no
SUBST_NOOP_OK?=		yes	# only for backwards compatiblity

_VARGROUPS+=		subst
_USER_VARS.subst=	SUBST_SHOW_DIFF SUBST_NOOP_OK
_PKG_VARS.subst=	SUBST_CLASSES
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

# _SUBST_IS_TEXT_FILE_CMD exits successfully if $$file is a text file.
_SUBST_IS_TEXT_FILE_CMD= \
	[ -z "`LC_ALL=C ${TR} -cd '\\0' < \"$$file\" | ${TR} '\\0' 'x'`" ]

.if ${SUBST_CLASSES:U:O} != ${SUBST_CLASSES:U:O:u}
PKG_FAIL_REASON+=	"[subst.mk] duplicate SUBST class in: ${SUBST_CLASSES:O}"
.endif

.for class in ${SUBST_CLASSES:O:u}
_SUBST_COOKIE.${class}=		${WRKDIR}/.subst_${class}_done

SUBST_FILTER_CMD.${class}?=	LC_ALL=C ${SED} ${SUBST_SED.${class}}
SUBST_VARS.${class}?=		# none
SUBST_MESSAGE.${class}?=	Substituting "${class}" in ${SUBST_FILES.${class}}
.  for v in ${SUBST_VARS.${class}}
SUBST_FILTER_CMD.${class}+=	-e s,@${v:C|[.[\\*^]|\\\\&|gW:Q}@,${${v}:S|\\|\\\\|gW:S|,|\\,|gW:S|&|\\\&|gW:S|${.newline}|\\${.newline}|gW:Q},g
.  endfor
.  if ${SUBST_SHOW_DIFF.${class}:U${SUBST_SHOW_DIFF}:tl} == yes
_SUBST_KEEP.${class}?=		LC_ALL=C ${DIFF} -u "$$file" "$$tmpfile" || true
.  endif
_SUBST_KEEP.${class}?=		${DO_NADA}
SUBST_SKIP_TEXT_CHECK.${class}?= \
				no
SUBST_NOOP_OK.${class}?=	${SUBST_NOOP_OK}
_SUBST_WARN.${class}=		${${SUBST_NOOP_OK.${class}:tl} == yes:?${INFO_MSG}:${WARNING_MSG}} "[subst.mk:${class}]"

.  if !empty(SUBST_SKIP_TEXT_CHECK.${class}:M[Yy][Ee][Ss])
_SUBST_IS_TEXT_FILE_CMD.${class}=	${TRUE}
.  else
_SUBST_IS_TEXT_FILE_CMD.${class}=	${_SUBST_IS_TEXT_FILE_CMD}
.  endif

.  if defined(SUBST_STAGE.${class})
${SUBST_STAGE.${class}}: subst-${class}
.  else
# SUBST_STAGE.* does not need to be defined.
#PKG_FAIL_REASON+=	"SUBST_STAGE missing for ${class}."
.  endif

.PHONY: subst-${class}
subst-${class}: ${_SUBST_COOKIE.${class}}

${_SUBST_COOKIE.${class}}:
	${RUN}								\
	message=${SUBST_MESSAGE.${class}:Q};				\
	[ "$$message" ] && ${ECHO_SUBST_MSG} "$$message";		\
	\
	cd ${WRKSRC};							\
	patterns=${SUBST_FILES.${class}:Q};				\
	set -f;								\
	for pattern in $$patterns; do					\
		set +f;							\
		changed=no;						\
		for file in $$pattern; do				\
			case $$file in ([!A-Za-z0-9/]*) file="./$$file";; esac; \
			tmpfile="$$file.subst.sav";			\
			[ -d "$$file" ] && continue;			\
			[ -f "$$file" ] || {				\
				${_SUBST_WARN.${class}} "Ignoring non-existent file \"$$file\"."; \
				continue;				\
			};						\
			${_SUBST_IS_TEXT_FILE_CMD.${class}} || {	\
				${_SUBST_WARN.${class}} "Ignoring non-text file \"$$file\"."; \
				continue;				\
			};						\
			${SUBST_FILTER_CMD.${class}} < "$$file" > "$$tmpfile";	\
			${CMP} -s "$$tmpfile" "$$file" && {		\
				${_SUBST_WARN.${class}} "Nothing changed in \"$$file\"."; \
				${RM} -f "$$tmpfile";			\
				continue;				\
			};						\
			[ -x "$$file" ] && ${CHMOD} +x "$$tmpfile";	\
			changed=yes;					\
			${_SUBST_KEEP.${class}};			\
			${MV} -f "$$tmpfile" "$$file"; 			\
			${ECHO} "$$file" >> ${.TARGET}.tmp;		\
		done;							\
	\
		[ "$$changed,${SUBST_NOOP_OK.${class}:tl}" = no,no ]	\
		&& ${FAIL_MSG} "[subst.mk:${class}] The filename pattern \"$$pattern\" has no effect."; \
	done; \
	\
	${TOUCH} ${TOUCH_FLAGS} ${.TARGET}.tmp;				\
	${MV} ${.TARGET}.tmp ${.TARGET}
.endfor
