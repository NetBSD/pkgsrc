# $NetBSD: Makefile,v 1.21 2004/04/24 00:49:45 wiz Exp $
#

DISTNAME=	mpeg_lib-1.3.1
PKGNAME=	mpeg-1.3.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mni.mcgill.ca/pub/mpeg/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/libs/ \
		ftp://ftp.gimp.org/pub/gimp/libs/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://starship.python.net/~gward/mpeglib/
COMMENT=	Library for decoding MPEG movies

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

ALL_TARGET=	libmpeg_lib.la

CONFIGURE_ENV+=	OPTIMIZE="${CFLAGS}" EXTRA_LDFLAGS="${LDFLAGS}"	\
		EXTRA_CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
