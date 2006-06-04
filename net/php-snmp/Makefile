# $NetBSD: Makefile,v 1.8 2006/06/04 16:26:55 joerg Exp $

MODNAME=		snmp
CATEGORIES+=		net
COMMENT=		PHP extension for SNMP

CONFLICTS=	php-snmp-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../lang/php/ext.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
