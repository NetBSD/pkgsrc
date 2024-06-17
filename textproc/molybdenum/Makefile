# $NetBSD: Makefile,v 1.8 2024/06/17 09:08:55 pin Exp $

DISTNAME=	molybdenum-0.1.10
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=gfannes/}
GITHUB_TAG=	release-v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/gfannes/molybdenum/
COMMENT=	Recursive search and replace CLI application
LICENSE=	eupl-v1.1

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
