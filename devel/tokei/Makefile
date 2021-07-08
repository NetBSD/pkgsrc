# $NetBSD: Makefile,v 1.3 2021/07/08 13:22:07 pin Exp $

DISTNAME=		tokei-12.1.2
CATEGORIES=		devel textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=XAMPPRocky/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pin@NetBSD.org
HOMEPAGE=		https://github.com/XAMPPRocky/tokei/
COMMENT=		Displays statistics about code
LICENSE=		apache-2.0 AND mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++	# rust, but needs a toolchain to link
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tokei ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
