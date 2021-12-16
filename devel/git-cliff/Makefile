# $NetBSD: Makefile,v 1.10 2021/12/16 13:14:48 pin Exp $

DISTNAME=	git-cliff-0.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=orhun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/orhun/git-cliff/
COMMENT=	Highly customizable Changelog Generator
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/git-cliff ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
