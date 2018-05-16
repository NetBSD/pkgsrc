# $NetBSD: alternatives.mk,v 1.13 2018/05/16 21:23:02 rillig Exp $
#
# This Makefile fragment handles the alternatives system, registering a
# package in the database.
#
# User-settable variables:
#
# (none)
#
# Package-settable variables:
#
# ALTERNATIVES_SRC
#	A _single_ file that contains the alternatives provided by the
#	package.
#
#	Default value: The name of the ALTERNATIVES file in the package
#	directory, if it exists. Otherwise, nothing.
#
#	Each line of the alternatives file contains two filenames:
#
#		wrapper   alternative
#
#	The wrapper is the command that is run by the user.
#	The alternative is the implementation of that command that is
#	provided by the package.
#	Both paths are relative to PREFIX.
#	The paths may use placeholders of the form @VARNAME@, which are
#	replaced with the actual values as per FILES_SUBST.
#
# Variables defined by this file:
#
# PKG_ALTERNATIVES
#	The path to the pkg_alternatives command.
#
# Keywords: alternatives

.if !defined(ALTERNATIVES_MK)
ALTERNATIVES_MK=	# defined

_VARGROUPS+=		alternatives
_PKG_VARS.alternatives=	ALTERNATIVES_SRC
_SYS_VARS.alternatives=	PKG_ALTERNATIVES

.if exists(${.CURDIR}/ALTERNATIVES)
ALTERNATIVES_SRC?=	${.CURDIR}/ALTERNATIVES
.endif
ALTERNATIVES_SRC?=	# none

.if !empty(ALTERNATIVES_SRC)

${WRKDIR}/.altinstall: ${ALTERNATIVES_SRC}
	@{ ${ECHO} 'if ${TEST} $${STAGE} = "POST-INSTALL"; then'; \
	${ECHO} '${CAT} >./+ALTERNATIVES <<EOF'; \
	${SED} ${FILES_SUBST_SED} <${ALTERNATIVES_SRC}; \
	${ECHO} 'EOF'; \
	${ECHO} 'if ${TEST} -x ${PKG_ALTERNATIVES}; then'; \
	${ECHO} '${PKG_ALTERNATIVES} -gs register ./+ALTERNATIVES'; \
	${ECHO} 'fi'; \
	${ECHO} 'fi'; \
	} >${WRKDIR}/.altinstall

${WRKDIR}/.altdeinstall: ${ALTERNATIVES_SRC}
	@{ ${ECHO} 'if ${TEST} $${STAGE} = "DEINSTALL"; then'; \
	${ECHO} 'if ${TEST} -x ${PKG_ALTERNATIVES}; then'; \
	${ECHO} '${PKG_ALTERNATIVES} -gs unregister ./+ALTERNATIVES'; \
	${ECHO} 'fi'; \
	${ECHO} '${RM} -f ./+ALTERNATIVES'; \
	${ECHO} 'fi'; \
	} >${WRKDIR}/.altdeinstall

PRINT_PLIST_AWK+=	/^libdata\/alternatives\// { next; }

PKG_ALTERNATIVES=	${LOCALBASE}/sbin/pkg_alternatives

INSTALL_TEMPLATES+=	${WRKDIR}/.altinstall
DEINSTALL_TEMPLATES+=	${WRKDIR}/.altdeinstall

.endif

.endif	# ALTERNATIVES_MK
