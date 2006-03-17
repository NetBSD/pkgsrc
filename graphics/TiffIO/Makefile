# $NetBSD: Makefile,v 1.6 2006/03/17 17:46:30 gdt Exp $
#

DISTNAME=		TiffIO-110c
PKGNAME=		TiffIO-1.1.0.3
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		http://artis.imag.fr/Software/TiffIO/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://artis.imag.fr/Software/TiffIO/
COMMENT=		Tiff support for QT image loader

USE_TOOLS+=     gmake
USE_LANGUAGES=  c c++

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile TiffIO.pro; \
		${SED} -e 's,-rpath.*$$,-rpath "${QTDIR}/lib",' < Makefile > Makefile.new; \
		${MV} Makefile.new Makefile; \
		)

do-install:
	(cd ${WRKSRC} && \
	libtool --mode=install ${INSTALL_PROGRAM} libTiffIO.la ${PREFIX}/qt3/plugins/imageformats && \
	libtool --finish ${PREFIX}/qt3/plugins/imageformats)

BUILD_ENV+=		QTDIR="${QTDIR}"

.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
