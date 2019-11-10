# $NetBSD: Makefile,v 1.1 2019/11/10 14:42:43 ng0 Exp $

GITHUB_TAG=		v${PKGVERSION_NOREV}
DISTNAME=		go-sqlite3-1.11.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=mattn/}
GITHUB_PROJECT=		go-sqlite3

MAINTAINER=		ng0@NetBSD.org
HOMEPAGE=		https://github.com/mattn/go-sqlite3
COMMENT=		Sqlite3 driver for Go using database/sql
LICENSE=		mit

GO_SRCPATH=		github.com/mattn/go-sqlite3
GO_DIST_BASE=		go-sqlite3-${PKGVERSION_NOREV}

MAKE_ENV+=		CGO_ENABLED=1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
