# $NetBSD: Makefile,v 1.3 2012/10/02 21:25:39 asau Exp $

MODNAME=		oci8
CATEGORIES+=		databases
COMMENT=		PHP extension for Oracle 8 (and above) databases

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
