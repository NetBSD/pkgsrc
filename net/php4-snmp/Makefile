# $NetBSD: Makefile,v 1.5 2004/04/25 00:18:14 xtraeme Exp $

MODNAME=		snmp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP4 extension for SNMP

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
