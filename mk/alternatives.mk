# $NetBSD: alternatives.mk,v 1.2 2005/01/25 15:37:25 jmmv Exp $
#
# This Makefile fragment handles the alternatives system, registering a
# package in the database.
#
# The ALTERNATIVES_SRC variable contains the path to a file listing the
# alternatives provided by the package.  It defaults to the ALTERNATIVES
# file in the current directory if found.  If this variable is empty, no
# actions are taken by this file.
#
# The PKG_ALTERNATIVES variable indicates wether the INSTALL/DEINSTALL
# scripts should do automatic alternatives handling, i.e., if they should
# register the installed packages into the wrappers database.  It is
# either YES or NO and defaults to YES.
#

.if !defined(ALTERNATIVES_MK)
ALTERNATIVES_MK=	# defined

PKG_ALTERNATIVES?=	YES

.if !defined(ALTERNATIVES_SRC)
.  if exists(${.CURDIR}/ALTERNATIVES)
ALTERNATIVES_SRC?=	${.CURDIR}/ALTERNATIVES
.  else
ALTERNATIVES_SRC?=
.  endif
.endif

.if !empty(ALTERNATIVES_SRC)

${WRKDIR}/.altinstall: ${ALTERNATIVES_SRC}
	@{ ${ECHO} ': $${PKG_ALTERNATIVES:=${PKG_ALTERNATIVES}}'; \
	${ECHO} 'if ${TEST} $${STAGE} = "POST-INSTALL"; then'; \
	${ECHO} '${CAT} >./+ALTERNATIVES <<EOF'; \
	${SED} ${FILES_SUBST_SED} <${ALTERNATIVES_SRC}; \
	${ECHO} 'EOF'; \
	${ECHO} 'case $${PKG_ALTERNATIVES} in [Yy][Ee][Ss])'; \
	${ECHO} '${_ALTERNATIVES_PROG} -s register ./+ALTERNATIVES ;;'; \
	${ECHO} 'esac'; \
	${ECHO} 'fi'; \
	} >${WRKDIR}/.altinstall

${WRKDIR}/.altdeinstall: ${ALTERNATIVES_SRC}
	@{ ${ECHO} ': $${PKG_ALTERNATIVES:=${PKG_ALTERNATIVES}}'; \
	${ECHO} 'if ${TEST} $${STAGE} = "DEINSTALL"; then'; \
	${ECHO} 'case $${PKG_ALTERNATIVES} in [Yy][Ee][Ss])'; \
	${ECHO} '${_ALTERNATIVES_PROG} -s unregister ./+ALTERNATIVES ;;'; \
	${ECHO} 'esac'; \
	${ECHO} '${RM} -f ./+ALTERNATIVES'; \
	${ECHO} 'fi'; \
	} >${WRKDIR}/.altdeinstall

PRINT_PLIST_AWK+=	/^libdata\/alternatives\// { next; }
PRINT_PLIST_AWK+=	/^@dirrm libdata\/alternatives/ { next; }

DEPENDS+=		pkg_alternatives>=1.0:../../pkgtools/pkg_alternatives

EVAL_PREFIX+=			PREFIX.pkg_alternatives=pkg_alternatives
PREFIX.alternatives_DEFAULT=	${LOCALBASE}
_ALTERNATIVES_PROG=		${PREFIX.pkg_alternatives}/sbin/pkg_alternatives

INSTALL_EXTRA_TMPL+=	${WRKDIR}/.altinstall
DEINSTALL_EXTRA_TMPL+=	${WRKDIR}/.altdeinstall
USE_PKGINSTALL=		YES

.endif

.endif	# ALTERNATIVES_MK
