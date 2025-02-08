# $NetBSD: Makefile,v 1.16 2025/02/08 03:18:21 taca Exp $

MODNAME=		snmp
PKGREVISION=		3
CATEGORIES+=		net
COMMENT=		PHP extension for SNMP

CONFLICTS=	php-snmp-[0-9]*

# use plain version withut =${PREFIX} - logic in config.m4 assumes net-snmp-config
# is under ${PREFIX} when it's passed, which fails if it's buildin (such as on Mac OS X)
CONFIGURE_ARGS+=	--with-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
