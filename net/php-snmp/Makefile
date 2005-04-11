# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:57 tv Exp $

MODNAME=		snmp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP extension for SNMP


CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../lang/php/ext.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
