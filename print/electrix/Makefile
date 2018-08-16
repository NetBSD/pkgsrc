# $NetBSD: Makefile,v 1.52 2018/08/16 13:56:26 wiz Exp $

DISTNAME=	electrix-0.2.0
PKGREVISION=	50
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=electrix/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://electrix.sourceforge.net/
COMMENT=	Application to view PDF files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	intltool pkg-config

do-configure:
	cd ${WRKSRC} && \
	${PYTHONBIN} ./waf configure --prefix=${DESTDIR}${PREFIX}

do-build:
	cd ${WRKSRC} && \
	${PYTHONBIN} ./waf build

do-install:
	cd ${WRKSRC} && \
	${PYTHONBIN} ./waf install

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
