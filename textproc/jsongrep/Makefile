# $NetBSD: Makefile,v 1.1 2026/03/29 15:28:31 pin Exp $

DISTNAME=	jsongrep-0.8.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=micahkepe/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/micahkepe/jsongrep/
COMMENT=	Path query language over JSON documents
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
