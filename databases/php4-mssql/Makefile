# $NetBSD: Makefile,v 1.4 2004/09/28 12:41:13 jdolecek Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP4 extension for MS SQL databases

.include "../../www/php4/Makefile.module"

USE_BUILDLINK3=		yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}/freetds

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
