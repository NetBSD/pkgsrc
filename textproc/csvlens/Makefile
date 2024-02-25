# $NetBSD: Makefile,v 1.20 2024/02/25 15:45:07 wiz Exp $

DISTNAME=	csvlens-0.7.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=YS-L/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/YS-L/csvlens/
COMMENT=	Command line csv viewer
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
