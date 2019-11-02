# $NetBSD: Makefile,v 1.5 2019/11/02 15:38:07 rillig Exp $

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

BUILDLINK_PASSTHRU_DIRS+=	${ORACLE_HOME}
CONFIGURE_ARGS+=		--with-${MODNAME}=shared,${ORACLE_HOME}

ONLY_FOR_PLATFORM=	Linux-*-* SunOS-*-*

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
