# $NetBSD: bad-env-usage.mk,v 1.2 2013/04/08 11:17:15 rodent Exp $
#

# Makefile intended to be included by packages that need to fix bad env usage:
#   http://code.google.com/p/ibus/issues/detail?id=1029

SUBST_CLASSES+=		badenv
SUBST_MESSAGE.badenv=	Fixing bad ENV usage.
SUBST_STAGE.badenv=	do-configure-pre-hook
SUBST_FILES.badenv=	${_REPLACE_LOCALEDIR}
SUBST_SED.badenv=	-e 's|^ENV[ 	:]*=|BIN_ENV=|'
SUBST_SED.badenv+=	-e 's|\$$(ENV)|$$\(BIN_ENV\)|g'
