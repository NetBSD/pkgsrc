# $NetBSD: Makefile,v 1.96 2003/04/16 13:27:21 mjl Exp $

.include "./Makefile.common"

PKGNAME=		ImageMagick-${DISTSUFFIX}

CATEGORIES=		graphics

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

# Some configure_args come from Makefile.common
CONFIGURE_ARGS+=	--without-perl

post-install:
	${INSTALL_DATA} ${WRKSRC}/Copyright.txt ${WRKSRC}/QuickStart.txt \
		${PREFIX}/share/ImageMagick

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../graphics/jasper/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
