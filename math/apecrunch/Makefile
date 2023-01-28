# $NetBSD: Makefile,v 1.2 2023/01/28 13:06:55 pin Exp $

DISTNAME=	apecrunch-0.0.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Gip-Gip/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Gip-Gip/apecrunch/
COMMENT=	Versitile TUI Speedcrunch Alternative
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config
USE_NCURSES=	yes #NCURSES_MOUSE_VERSION

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncursesw}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/apecrunch \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
