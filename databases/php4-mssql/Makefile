# $NetBSD: Makefile,v 1.3 2004/07/14 08:03:16 jdolecek Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP4 extension for MS SQL databases

DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../www/php4/Makefile.module"

USE_BUILDLINK3=		yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}/freetds

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
