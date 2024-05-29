# $NetBSD: Makefile,v 1.16 2024/05/29 16:31:40 adam Exp $

# When updating this package, be sure to also update the version constraint
# on sqlite3 in this file and buildlink3.mk.
DISTNAME=	direct-sqlite-2.3.29
PKGREVISION=	2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Low-level binding to SQLite3 including UTF8 and BLOB support
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-f systemlib

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.45.3
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
