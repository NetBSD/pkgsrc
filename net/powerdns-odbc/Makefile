# $NetBSD: Makefile,v 1.2 2025/06/30 11:03:26 jperkin Exp $

.include "../../net/powerdns/backend.mk"

PKGNAME=		${DISTNAME:S/pdns/powerdns-odbc/}
COMMENT=		ODBC backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="godbc"
CONFIGURE_ARGS+=	--with-unixodbc=${BUILDLINK_PREFIX.unixodbc}

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
