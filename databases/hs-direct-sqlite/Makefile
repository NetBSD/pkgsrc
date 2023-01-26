# $NetBSD: Makefile,v 1.5 2023/01/26 08:53:08 pho Exp $

DISTNAME=	direct-sqlite-2.3.27
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Low-level binding to SQLite3 including UTF8 and BLOB support
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-f systemlib

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
