# $NetBSD: Makefile,v 1.85 2002/09/09 22:07:21 markd Exp $

DISTNAME=		ImageMagick-5.4.8-2
PKGNAME=		${DISTNAME:S/-2/.2/}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.nluug.nl/pub/ImageMagick/ \
			ftp://ftp.yggdrasil.com/mirrors/site/ftp.simplesystems.org/pub/ImageMagick/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/ImageMagick/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Package for display and interactive manipulation of images

CONFLICTS=		geomview-[0-9]*    # both have a program named 'animate'

DEPENDS+=		mpeg2codec-1.2:../../graphics/mpeg2codec

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

WRKSRC=			${WRKDIR}/${DISTNAME:S/-2//}

# c++ broken as of 'gcc version 2.95.3 20010315 (release) (NetBSD nb1)'
NOT_FOR_PLATFORM=	NetBSD-*-sparc64

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD ||  ${OPSYS} == SunOS)
BUILD_DEPENDS+=		bash>=2.0:../../shells/bash2

CONFIGURE_SCRIPT=	${LOCALBASE}/bin/bash ./configure
.endif

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

.include "../../archivers/bzip2/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
