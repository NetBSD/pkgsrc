# $NetBSD: Makefile,v 1.10 2022/09/26 13:52:48 pin Exp $

DISTNAME=	csview-1.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=wfxr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/wfxr/csview/
COMMENT=	High performance csv viewer with cjk/emoji support
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/csview ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
