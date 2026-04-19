# $NetBSD: Makefile,v 1.3 2026/04/19 14:47:33 wiz Exp $

DISTNAME=	jsongrep-0.9.0
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
