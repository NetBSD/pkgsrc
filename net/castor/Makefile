# $NetBSD: Makefile,v 1.5 2022/08/11 05:09:08 gutteridge Exp $

DISTNAME=	0.9.0
PKGNAME=	castor-0.9.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://git.sr.ht/~julienxx/castor/archive/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~julienxx/castor/
COMMENT=	Client for plain-text protocols like Gemini, Gopher and Finger
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin share/applications share/examples/castor share/icons/hicolor/scalable/apps

WRKSRC=			${WRKDIR}/castor-${DISTNAME}

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk3}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/castor \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/Castor.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/data/settings.toml \
		${DESTDIR}${PREFIX}/share/examples/castor
	${INSTALL_DATA} ${WRKSRC}/data/org.typed-hole.castor.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
