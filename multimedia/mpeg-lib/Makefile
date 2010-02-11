# $NetBSD: Makefile,v 1.8 2010/02/11 20:04:28 joerg Exp $
#

DISTNAME=	mpeg_lib-1.3.1
PKGNAME=	mpeg-1.3.1
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.mni.mcgill.ca/pub/mpeg/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/libs/ \
		ftp://ftp.gimp.org/pub/gimp/libs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gerg.ca/software/mpeglib/
COMMENT=	Library for decoding MPEG movies

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

BUILD_TARGET=	libmpeg_lib.la

CONFIGURE_ENV+=	OPTIMIZE=${CFLAGS:M*:Q} EXTRA_LDFLAGS=${LDFLAGS:M*:Q}	\
		EXTRA_CPPFLAGS=${CPPFLAGS:M*:Q}

INSTALLATION_DIRS+=	include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/mpeg.h ${DESTDIR}${PREFIX}/include
	libtool --mode=install ${INSTALL_LIB} ${WRKSRC}/libmpeg_lib.la ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
