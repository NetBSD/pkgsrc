# $NetBSD: Makefile,v 1.22 2024/03/27 09:47:45 pin Exp $

DISTNAME=	csvlens-0.8.1
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
