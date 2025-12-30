# $NetBSD: Makefile,v 1.16 2025/12/30 19:08:21 pin Exp $

DISTNAME=	tokei-14.0.0
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=XAMPPRocky/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/XAMPPRocky/tokei/
COMMENT=	Displays statistics about code
LICENSE=	apache-2.0 AND mit

.include "cargo-depends.mk"

RUST_REQ=		1.71.0
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tokei \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
