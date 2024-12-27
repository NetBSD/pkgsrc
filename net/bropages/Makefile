# $NetBSD: Makefile,v 1.2 2024/12/27 21:28:21 pin Exp $

DISTNAME=	bropages-1.41.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=pombadev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pombadev/bropages/
COMMENT=	CLI to interact with bropages.org
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
