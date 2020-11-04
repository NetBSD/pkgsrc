# $NetBSD: Makefile,v 1.5 2020/11/04 19:24:40 pin Exp $

DISTNAME=	onefetch-2.6.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=o2sh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/o2sh/onefetch/
COMMENT=	Git repository summary on your terminal
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c	# rust, but needs a toolchain to link
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/onefetch ${DESTDIR}${PREFIX}/bin

DEPENDS+=		git-base-[0-9]*:../../devel/git-base

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
