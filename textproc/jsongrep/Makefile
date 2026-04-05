# $NetBSD: Makefile,v 1.2 2026/04/05 12:10:24 wiz Exp $

DISTNAME=	jsongrep-0.8.1
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
