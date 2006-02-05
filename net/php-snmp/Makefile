# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:29 joerg Exp $

MODNAME=		snmp
PKGREVISION=		1
CATEGORIES+=		net
COMMENT=		PHP extension for SNMP


CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../lang/php/ext.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
