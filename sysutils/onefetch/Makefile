# $NetBSD: Makefile,v 1.23 2023/04/27 18:16:41 pin Exp $

DISTNAME=	onefetch-2.17.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=o2sh/}
GITHUB_TAG=	7be7ea92a29117706af73f4ff9799a9a5a3d76b1

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/o2sh/onefetch/
COMMENT=	Git repository summary on your terminal
LICENSE=	mit

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/onefetch \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/onefetch.1  \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/onefetch.1

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

.include "../../lang/rust/cargo.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
