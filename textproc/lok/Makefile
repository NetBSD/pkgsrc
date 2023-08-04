# $NetBSD: Makefile,v 1.11 2023/08/04 09:03:56 pin Exp $

DISTNAME=	lok-0.2.3
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wyhaya/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/wyhaya/lok/
COMMENT=	Count the number of codes
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
