# $NetBSD: Makefile,v 1.1 2021/01/26 13:31:08 pin Exp $

DISTNAME=	lsfp-0.4.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=The-Noah/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/The-Noah/lsfp/
COMMENT=	Cross-platform alternative to ls
LICENSE=	mit

USE_LANGUAGES=	c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/lsfp ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
