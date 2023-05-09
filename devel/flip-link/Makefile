# $NetBSD: Makefile,v 1.1 2023/05/09 21:58:30 nikita Exp $

DISTNAME=	flip-link-0.1.5
CATEGORIES=	devel
MAINTAINER=	nikita@NetBSD.org
MASTER_SITES=	${MASTER_SITE_GITHUB:=knurling-rs/}
GITHUB_PROJECT=	flip-link
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/knurling-rs/flip-link/
COMMENT=	Zero-cost stack overflow protection for embedded programs
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/flip-link ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
