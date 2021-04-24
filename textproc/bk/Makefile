# $NetBSD: Makefile,v 1.4 2021/04/24 19:35:44 pin Exp $

DISTNAME=	bk-0.5.2
# WARNING: Do not update this package!  Newer versions require rust-1.51
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aeosynth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aeosynth/bk/
COMMENT=	Terminal Epub reader
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=			c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bk ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
