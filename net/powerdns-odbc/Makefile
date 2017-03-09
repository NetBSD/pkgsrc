# $NetBSD: Makefile,v 1.1 2017/03/09 13:52:34 fhajny Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-odbc/}
COMMENT=		ODBC backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="godbc"
CONFIGURE_ARGS+=	--with-unixodbc=${BUILDLINK_PREFIX.unixodbc}

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
