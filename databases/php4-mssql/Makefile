# $NetBSD: Makefile,v 1.1.1.1 2003/12/14 14:05:29 jdolecek Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP4 extension for MS SQL databases

.include "../../www/php4/Makefile.module"

USE_BUILDLINK2=		# defined

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}/freetds

.include "../../databases/freetds/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
