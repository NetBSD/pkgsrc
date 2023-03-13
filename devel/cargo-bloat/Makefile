# $NetBSD: Makefile,v 1.2 2023/03/13 07:31:25 wiz Exp $

DISTNAME=	cargo-bloat-0.11.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=RazrFalcon/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/RazrFalcon/cargo-bloat/
COMMENT=	Find out what takes most of the space in your executable
LICENSE=	mit

USE_LANGUAGES=		c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-bloat ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
