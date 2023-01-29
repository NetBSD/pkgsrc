# $NetBSD: Makefile,v 1.2 2023/01/29 20:11:10 pin Exp $

DISTNAME=	nora-0.2.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jokler/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jokler/nora/
COMMENT=	Freezes the screen for other programs
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/nora ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
