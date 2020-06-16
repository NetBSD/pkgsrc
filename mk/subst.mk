# $NetBSD: subst.mk,v 1.100 2020/06/16 18:13:54 rillig Exp $
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
#	Whether it is ok to have patterns in SUBST_FILES that don't
#	contain any of the patterns from SUBST_SED or SUBST_VARS and
#	thus are not modified at all.
#
#	This setting only detects redundant filename patterns.  It does
#	not detect redundant patterns in SUBST_SED.
#
#	Identity substitutions like s|man|man| do not count as no-ops
#	since their replacement part usually comes from a variable, such
#	as PKGMANDIR.
#
#	Defaults to no.  Will be removed after 2020Q3.
#
# Package-settable variables:
#
# SUBST_CLASSES
#	A list of class names.  When adding new classes to this list, be
#	sure to append them (+=) instead of overriding them (=).
#	The order in which the classes are applied is unspecified.
#
# SUBST_STAGE.<class>
#	"stage" at which we do the text replacement. Should be one of
#	{pre,do,post}-{extract,configure,build,install}.
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
#	Whether to allow filename patterns in SUBST_FILES that don't
#	contain any of the patterns from SUBST_SED.
#
#	Defaults to no, since May 2020.
#
#	Typical reasons to change this to yes are:
#
#	1.  SUBST_FILES is generated dynamically (e.g., via find) and
#	    may include unaffected files.
#
#	2.  There are multiple SUBST_SED patterns, and some of these
#	    do not count as identity substitution since they contain
#	    ".*" or similar parts.
#
# See also:
#	PLIST_SUBST
#
# Keywords: subst
#

SUBST_SHOW_DIFF?=	no
SUBST_NOOP_OK?=		yes	# for the stable branch 2020Q2

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

.if defined(SUBST_FILTER_CMD.${class}) && (defined(SUBST_SED.${class}) || defined(SUBST_VARS.${class}))
PKG_FAIL_REASON+=		"[subst.mk:${class}] SUBST_FILTER_CMD and SUBST_SED/SUBST_VARS cannot be combined."
.endif

SUBST_FILTER_CMD.${class}?=	LC_ALL=C ${SED} ${SUBST_SED.${class}}
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
	${RUN} set -u;							\
	message=${SUBST_MESSAGE.${class}:Q};				\
	[ "$$message" ] && ${ECHO_SUBST_MSG} "$$message";		\
	\
	cd ${WRKSRC};							\
	patterns=${SUBST_FILES.${class}:Q};				\
	set -f;								\
	noop_count='';							\
	noop_patterns='';						\
	noop_sep='';							\
	for pattern in $$patterns; do					\
		set +f;							\
		found_any=no;						\
		for file in $$pattern; do				\
			case $$file in ([!A-Za-z0-9/]*) file="./$$file";; esac; \
			tmpfile="$$file.subst.sav";			\
			[ -d "$$file" ] && continue;			\
			[ -f "$$file" ] || {				\
				${_SUBST_WARN.${class}} "Ignoring nonexistent file \"$$file\"."; \
				continue;				\
			};						\
			${_SUBST_IS_TEXT_FILE_CMD.${class}} || {	\
				${_SUBST_WARN.${class}} "Ignoring non-text file \"$$file\"."; \
				continue;				\
			};						\
			${SUBST_FILTER_CMD.${class}} < "$$file" > "$$tmpfile"; \
			${CMP} -s "$$tmpfile" "$$file" && {		\
				${AWK} -f ${PKGSRCDIR}/mk/scripts/subst-identity.awk -- ${SUBST_SED.${class}} \
				&& found_text=$$(LC_ALL=C ${SED} -n ${SUBST_SED.${class}:C,^['"]?s.*,&p,} "$$file") \
				&& [ -n "$$found_text" ]		\
				&& found_any=yes			\
				|| ${_SUBST_WARN.${class}} "Nothing changed in \"$$file\"."; \
				${RM} -f "$$tmpfile";			\
				continue;				\
			};						\
			[ -x "$$file" ] && ${CHMOD} +x "$$tmpfile";	\
			found_any=yes;					\
			${_SUBST_KEEP.${class}};			\
			${MV} -f "$$tmpfile" "$$file"; 			\
			${ECHO} "$$file" >> ${.TARGET}.tmp;		\
		done;							\
									\
		[ "$$found_any,${SUBST_NOOP_OK.${class}:tl}" = no,no ] && { \
			noop_count="$$noop_count+";			\
			noop_patterns="$$noop_patterns$$noop_sep$$pattern"; \
			noop_sep=" ";					\
		};							\
	done;								\
	\
	case $$noop_count in						\
	('')	;;							\
	(+)	${FAIL_MSG} "[subst.mk:${class}] The filename pattern \"$$noop_patterns\" has no effect.";; \
	(*)	${FAIL_MSG} "[subst.mk:${class}] The filename patterns \"$$noop_patterns\" have no effect.";; \
	esac;								\
	${TOUCH} ${TOUCH_FLAGS} ${.TARGET}.tmp;				\
	${MV} ${.TARGET}.tmp ${.TARGET}
.endfor
