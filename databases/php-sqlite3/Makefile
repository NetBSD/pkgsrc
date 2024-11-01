# $NetBSD: Makefile,v 1.14 2024/11/01 00:51:03 wiz Exp $

MODNAME=		sqlite3
CATEGORIES+=		databases
COMMENT=		PHP extension for SQLite databases
PKGREVISION=		13

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
