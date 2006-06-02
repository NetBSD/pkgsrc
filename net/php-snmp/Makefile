# $NetBSD: Makefile,v 1.7 2006/06/02 18:27:57 joerg Exp $

MODNAME=		snmp
CATEGORIES+=		net
COMMENT=		PHP extension for SNMP

CONFLICTS=	php-snmp-[0-9]

CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../lang/php/ext.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
