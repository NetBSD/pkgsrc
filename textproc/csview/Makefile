# $NetBSD: Makefile,v 1.13 2024/03/04 20:17:07 pin Exp $

DISTNAME=	csview-1.2.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=wfxr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/wfxr/csview/
COMMENT=	High performance csv viewer with cjk/emoji support
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/csview \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
