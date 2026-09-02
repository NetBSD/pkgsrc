# $NetBSD: Makefile,v 1.37 2026/09/02 19:01:16 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 20
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
