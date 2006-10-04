# $NetBSD: Makefile,v 1.7 2006/10/04 21:50:09 wiz Exp $
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

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

BUILD_TARGET=	libmpeg_lib.la

CONFIGURE_ENV+=	OPTIMIZE=${CFLAGS:M*:Q} EXTRA_LDFLAGS=${LDFLAGS:M*:Q}	\
		EXTRA_CPPFLAGS=${CPPFLAGS:M*:Q}

.include "../../mk/bsd.pkg.mk"
