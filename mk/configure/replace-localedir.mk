# $NetBSD: replace-localedir.mk,v 1.3 2020/03/30 22:57:18 rillig Exp $

######################################################################
### replace-localedir (PRIVATE)
######################################################################
### replace-localedir replaces the path to the locale directory in
### various Makefiles with the one chosen by pkgsrc (PKGLOCALEDIR).
###
.PHONY: replace-localedir
replace-localedir:
	@${DO_NADA}

replace-localedir: subst-pkglocaledir

_PKGLOCALEDIR=	${PREFIX}/${PKGLOCALEDIR}/locale

REPLACE_LOCALEDIR_PATTERNS?=	# empty
_REPLACE_LOCALEDIR_PATTERNS=	${REPLACE_LOCALEDIR_PATTERNS}
.if defined(HAS_CONFIGURE)
_REPLACE_LOCALEDIR_PATTERNS+=	[Mm]akefile.in*
.else
_REPLACE_LOCALEDIR_PATTERNS+=	[Mm]akefile*
.endif
_REPLACE_LOCALEDIR_PATTERNS_FIND_cmd=					\
	cd ${WRKSRC} &&							\
	${ECHO} "__dummy-entry__" &&					\
	${FIND} . \( ${_REPLACE_LOCALEDIR_PATTERNS:C/.*/-o -name "&"/g:S/-o//1} \) -print | \
	${SED} -e 's|^\./||' |						\
	${SORT} -u

REPLACE_LOCALEDIR?=	# empty
_REPLACE_LOCALEDIR=	\
	${REPLACE_LOCALEDIR}						\
	${_REPLACE_LOCALEDIR_PATTERNS_FIND_cmd:sh:N__dummy-entry__:N*.orig}

.if empty(USE_PKGLOCALEDIR:M[nN][oO])
SUBST_CLASSES+=			pkglocaledir
.endif
SUBST_STAGE.pkglocaledir=	do-configure-pre-hook
SUBST_MESSAGE.pkglocaledir=	Fixing locale directory references.
SUBST_FILES.pkglocaledir=	${_REPLACE_LOCALEDIR}
SUBST_SED.pkglocaledir=		\
	-e 's|^\(localedir[ 	:]*=\).*|\1 ${_PKGLOCALEDIR}|'		\
	-e 's|^\(itlocaledir[ 	:]*=\).*|\1 ${_PKGLOCALEDIR}|'		\
	-e 's|^\(gnulocaledir[ 	:]*=\).*|\1 ${_PKGLOCALEDIR}|'		\
	-e 's|\(-DLOCALEDIR[ 	]*=\)[^ 	]*\(\.\*\)|\1"\\"${_PKGLOCALEDIR}\\""\2|'
SUBST_NOOP_OK.pkglocaledir=	yes
