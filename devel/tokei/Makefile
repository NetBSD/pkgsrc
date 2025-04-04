# $NetBSD: Makefile,v 1.13 2025/04/04 20:19:32 pin Exp $

DISTNAME=	v13.0.0-alpha.8
PKGNAME=	${GITHUB_PROJECT}-13.0.0.alpha8
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=XAMPPRocky/}
GITHUB_PROJECT=	tokei
GITHUB_TAG=	v13.0.0-alpha.8

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
