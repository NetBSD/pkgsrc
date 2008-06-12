# $NetBSD: Makefile,v 1.10 2008/06/12 02:14:41 joerg Exp $

MODNAME=		snmp
CATEGORIES+=		net
COMMENT=		PHP extension for SNMP

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-snmp-[0-9]*

# use plain version withut =${PREFIX} - logic in config.m4 assumes net-snmp-config
# is under ${PREFIX} when it's passed, which fails if it's buildin (such as on Mac OS X)
CONFIGURE_ARGS+=	--with-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
