# $NetBSD: Makefile,v 1.2 2004/04/25 01:12:49 xtraeme Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP4 extension for MS SQL databases

.include "../../www/php4/Makefile.module"

USE_BUILDLINK3=		yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}/freetds

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
