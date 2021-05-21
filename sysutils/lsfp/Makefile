# $NetBSD: Makefile,v 1.4 2021/05/21 07:00:59 pin Exp $

DISTNAME=	lsfp-0.5.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=The-Noah/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/The-Noah/lsfp/
COMMENT=	Cross-platform alternative to ls
LICENSE=	mit

USE_LANGUAGES=	c	# rust, but needs a toolchain to link

CARGO_CRATE_DEPENDS+=	cc-1.0.66

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/lsfp ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
