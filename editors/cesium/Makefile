# $NetBSD: Makefile,v 1.5 2021/08/05 08:42:25 pin Exp $

DISTNAME=	cesium-0.2.1
CATEGORIES=	editors
MASTER_SITES=	https://gitlab.com/NoahJelen/cesium/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://gitlab.com/NoahJelen/cesium/
COMMENT=	Notepad-like text editor
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config
USE_NCURSES=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncursesw}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cesium ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/cesium.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cesium.1

.include "../../lang/rust/cargo.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
