# $NetBSD: Makefile,v 1.4 2003/11/08 06:58:10 jdolecek Exp $

MODNAME=		snmp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP4 extension for SNMP

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../net/net-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
