# $NetBSD: Makefile,v 1.89 2003/01/03 23:04:35 wiz Exp $

DISTNAME=		ImageMagick-${IM_MAJOR_VER}-${IM_MINOR_VER}
PKGNAME=		ImageMagick-${IM_MAJOR_VER}.${IM_MINOR_VER}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.nluug.nl/pub/ImageMagick/ \
			ftp://ftp.yggdrasil.com/mirrors/site/ftp.simplesystems.org/pub/ImageMagick/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/ImageMagick/ \
			http://imagemagick.sourceforge.net/http/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Package for display and interactive manipulation of images

DEPENDS+=		mpeg2codec-1.2:../../graphics/mpeg2codec

CONFLICTS=		geomview-[0-9]*    # both have a program named 'animate'

IM_MAJOR_VER=		5.5.3
IM_MINOR_VER=		2

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

WRKSRC=			${WRKDIR}/ImageMagick-${IM_MAJOR_VER}

PLIST_SUBST+=		IM_MAJOR_VER=${IM_MAJOR_VER}

# c++ broken as of 'gcc version 2.95.3 20010315 (release) (NetBSD nb1)'
NOT_FOR_PLATFORM=	NetBSD-*-sparc64

.include "../../mk/bsd.prefs.mk"

# Avoid compiler bug on "arm32"
.if (${MACHINE_ARCH} == arm32)
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
