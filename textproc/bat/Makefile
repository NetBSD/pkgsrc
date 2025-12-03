# $NetBSD: Makefile,v 1.39 2025/12/03 09:18:16 pin Exp $

DISTNAME=	bat-0.26.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGBASE}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/bat/
COMMENT=	Clone of cat with syntax highlighting
LICENSE=	apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.87.0
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	cd ${WRKSRC}/target/release && \
		${FIND} . -name bat.1 \
			-type f \
			-exec ${INSTALL_MAN} '{}' ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 \;

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
