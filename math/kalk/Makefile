# $NetBSD: Makefile,v 1.7 2021/05/27 20:44:36 pin Exp $

DISTNAME=	kalk-0.5.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=PaddiM8/}
GITHUB_PROJECT=	kalk
GITHUB_TAG=	5848c36125bb487c0f909faef965437e131e917c

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
