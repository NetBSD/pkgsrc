# $NetBSD: Makefile,v 1.2 2010/06/27 20:38:04 joerg Exp $

MODNAME=		oci8
CATEGORIES+=		databases
COMMENT=		PHP extension for Oracle 8 (and above) databases

PKG_DESTDIR_SUPPORT=	user-destdir

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
