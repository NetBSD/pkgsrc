# $NetBSD: Makefile,v 1.8 2024/06/01 14:10:03 pin Exp $

DISTNAME=	bacon-2.18.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Canop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://dystroy.org/bacon/
COMMENT=	Background rust code check
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
