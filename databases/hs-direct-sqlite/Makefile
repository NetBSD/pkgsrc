# $NetBSD: Makefile,v 1.7 2023/04/19 08:08:06 adam Exp $

DISTNAME=	direct-sqlite-2.3.27
PKGREVISION=	2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Low-level binding to SQLite3 including UTF8 and BLOB support
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-f systemlib

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
