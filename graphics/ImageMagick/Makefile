# $NetBSD: Makefile,v 1.95 2003/04/15 11:11:50 mjl Exp $

IM_MAJOR_VER=		5.5.6
IM_MINOR_VER=		NONE
IM_MAJOR_LIB_VER=	${IM_MAJOR_VER}-Q16

.if (${IM_MINOR_VER} != NONE)
DISTNAME=		ImageMagick-${IM_MAJOR_VER}-${IM_MINOR_VER}
PKGNAME=		ImageMagick-${IM_MAJOR_VER}.${IM_MINOR_VER}
.else
DISTNAME=		ImageMagick-${IM_MAJOR_VER}
PKGNAME=		ImageMagick-${IM_MAJOR_VER}
.endif
WRKSRC=			${WRKDIR}/ImageMagick-${IM_MAJOR_VER}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.nluug.nl/pub/ImageMagick/ \
			ftp://ftp.yggdrasil.com/mirrors/site/ftp.simplesystems.org/pub/ImageMagick/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/ImageMagick/ \
			ftp://ftp.sunet.se/pub/multimedia/graphics/ImageMagick/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/ImageMagick/ \
			http://imagemagick.sourceforge.net/http/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Package for display and interactive manipulation of images

DEPENDS+=		mpeg2codec-1.2:../../graphics/mpeg2codec

CONFLICTS=		geomview-[0-9]*    # both have a program named 'animate'

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PLIST_SUBST+=		IM_MAJOR_VER=${IM_MAJOR_VER}
PLIST_SUBST+=		IM_MAJOR_LIB_VER=${IM_MAJOR_LIB_VER}

.include "../../mk/bsd.prefs.mk"

# c++ broken as of 'gcc version 2.95.3 20010315 (release) (NetBSD nb1)'
NOT_FOR_PLATFORM=	NetBSD-*-sparc64

# NetBSD 1.5's gcc is too old to compile this pkg
.include "../../lang/gcc/buildlink2.mk"
GCC_REQD=		2.95.3

# Avoid compiler bug on "mipsel" (cobalt?)
.if (${MACHINE_ARCH} == mipsel)
CFLAGS=			-O
.endif

# For things for which we do not specify an explicit dependency above, disable
# so that we don't cause implicit "hidden" dependencies.  Users may reenable
# any of these manually as desired (PerlMagick should probably be a separate
# pkg, however).
CONFIGURE_ARGS+=	--without-perl --without-dps --without-fpx \
			--without-hdf --without-jbig --without-threads \
			--without-ttf --without-wmf --without-xml \
			--without-lcms

post-install:
	${INSTALL_DATA} ${WRKSRC}/Copyright.txt ${WRKSRC}/QuickStart.txt \
		${PREFIX}/share/ImageMagick

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../graphics/jasper/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
