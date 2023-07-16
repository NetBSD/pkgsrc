# $NetBSD: Makefile,v 1.2 2023/07/16 21:16:14 pin Exp $

DISTNAME=	garden-0.8.0
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
