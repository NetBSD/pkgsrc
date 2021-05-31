# $NetBSD: Makefile,v 1.9 2021/05/31 20:53:46 pin Exp $

DISTNAME=	kalk-0.5.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=PaddiM8/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kalk.strct.net/
COMMENT=	CLI calculator supporting user defined variables and functions
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++	# rust, but needs a toolchain to link
USE_TOOLS+=	m4

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/kalk ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
