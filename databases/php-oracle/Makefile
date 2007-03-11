# $NetBSD: Makefile,v 1.1.1.1 2007/03/11 16:46:17 grant Exp $

MODNAME=		oracle
CATEGORIES+=		databases
COMMENT=		PHP extension for Oracle databases

USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.if !defined(ORACLE_HOME)
PKG_FAIL_REASON+=	"You must set ORACLE_HOME to the location of your Oracle installation"
.elif !exists(${ORACLE_HOME})
PKG_FAIL_REASON+=	"The location of ORACLE_HOME does not exist"
.endif

BUILDLINK_PASSTHRU_DIRS+=       ${ORACLE_HOME}
CONFIGURE_ARGS+=		--with-${MODNAME}=shared,${ORACLE_HOME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
