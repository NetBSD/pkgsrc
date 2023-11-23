# $NetBSD: Makefile,v 1.12 2023/11/23 11:02:21 wiz Exp $

DISTNAME=	direct-sqlite-2.3.28
PKGREVISION=	2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Low-level binding to SQLite3 including UTF8 and BLOB support
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-f systemlib

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.32.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
