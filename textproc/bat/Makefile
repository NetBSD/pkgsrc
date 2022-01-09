# $NetBSD: Makefile,v 1.25 2022/01/09 23:16:43 fox Exp $

DISTNAME=	bat-0.19.0
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

USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bat ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/target/release && \
		${FIND} . -name bat.1 \
			-type f \
			-exec ${INSTALL_MAN} '{}' ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 \;

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
