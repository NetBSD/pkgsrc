# $NetBSD: Makefile,v 1.8 2022/05/08 09:13:35 pin Exp $

DISTNAME=	bk-0.5.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aeosynth/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aeosynth/bk/
COMMENT=	Terminal Epub reader
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bk ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
