# $NetBSD: Makefile,v 1.6 2021/05/19 10:56:13 pin Exp $

DISTNAME=	kalk-0.4.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=PaddiM8/}
GITHUB_PROJECT=	kalk
GITHUB_TAG=	93aa751f66c3e228110ff69dcc86e2542f8d297b

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
