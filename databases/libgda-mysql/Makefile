# $NetBSD: Makefile,v 1.40 2026/11/11 11:52:11 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 23
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
