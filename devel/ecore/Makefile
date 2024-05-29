# $NetBSD: Makefile,v 1.47 2024/05/29 16:32:00 adam Exp $

DISTNAME=	ecore-1.7.10
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://enlightenment.org/
COMMENT=	Event Abstraction and Modular Convenience Library
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-ecore-directfb

# Explicitly disable epoll/inotify on illumos, provided for Linux compat only.
CONFIGURE_ARGS.SunOS+=	--disable-epoll
CONFIGURE_ARGS.SunOS+=	--disable-inotify

INSTALLATION_DIRS=	share/doc/ecore

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/ecore

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../graphics/evas-buffer/buildlink3.mk"
.include "../../graphics/evas-software-x11/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
