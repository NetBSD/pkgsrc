# $NetBSD: Makefile,v 1.35 2023/10/24 22:11:17 wiz Exp $

DISTNAME=	bat-0.24.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGBASE}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/bat/
COMMENT=	Clone of cat with syntax highlighting
LICENSE=	apache-2.0

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	cd ${WRKSRC}/target/release && \
		${FIND} . -name bat.1 \
			-type f \
			-exec ${INSTALL_MAN} '{}' ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 \;

# for libgit2-sys crate
.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
