# $NetBSD: Makefile,v 1.2 2022/01/13 20:32:08 wiz Exp $

DISTNAME=	hexyl-0.9.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/hexyl/
COMMENT=	Command-line hex viewer
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES=		c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${PKGBASE} ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
