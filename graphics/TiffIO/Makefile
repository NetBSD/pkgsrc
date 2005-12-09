# $NetBSD: Makefile,v 1.1.1.1 2005/12/09 15:47:34 gdt Exp $
#

DISTNAME=		TiffIO-110c
PKGNAME=		TiffIO-1.1.0.3
CATEGORIES=		graphics
MASTER_SITES=		http://artis.imag.fr/Software/TiffIO/
EXTRACT_SUFX=		.tgz

MAINTAINER=		gdt@ir.bbn.com
HOMEPAGE=		http://artis.imag.fr/Software/TiffIO/
COMMENT=		Tiff support for QT image loader

# We need qmake to build package's Makefile
BUILDLINK_DEPMETHOD.qt3-tools=  build

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

# XXX The package uses an included version of tiff.
#.include "../../graphics/tiff/buildlink3.mk"

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
