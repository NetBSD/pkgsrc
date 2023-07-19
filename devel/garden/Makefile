# $NetBSD: Makefile,v 1.3 2023/07/19 05:59:35 pin Exp $

DISTNAME=	garden-0.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=davvid/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://davvid.github.io/garden/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
