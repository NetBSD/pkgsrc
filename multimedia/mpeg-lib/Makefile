# $NetBSD: Makefile,v 1.14 2026/08/04 20:29:10 wiz Exp $

DISTNAME=	mpeg_lib-1.3.1
PKGNAME=	mpeg-1.3.1
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/libs/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.gerg.ca/software/mpeglib/
COMMENT=	Library for decoding MPEG movies

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

BUILD_TARGET=	libmpeg_lib.la

CONFIGURE_ENV+=	OPTIMIZE=${CFLAGS:M*:Q} EXTRA_LDFLAGS=${LDFLAGS:M*:Q}	\
		EXTRA_CPPFLAGS=${CPPFLAGS:M*:Q}

INSTALLATION_DIRS+=	include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/mpeg.h ${DESTDIR}${PREFIX}/include
	libtool --mode=install ${INSTALL_LIB} ${WRKSRC}/libmpeg_lib.la ${DESTDIR}${PREFIX}/lib

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
