# $NetBSD: Makefile,v 1.9 2001/06/11 06:34:22 jlam Exp $
#

DISTNAME=	psiconv-0.6.1
CATEGORIES=	converters
MASTER_SITES=	http://huizen.dds.nl/~frodol/psiconv/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://huizen.dds.nl/~frodol/psiconv/
COMMENT=	PSION 5 file format data conversion utilities

.if !exists(/usr/include/getopt.h)
DEPENDS+=	libgetopt-[0-9]*:../../devel/libgetopt
LIBS=		-lgetopt
.endif
DEPENDS+=	ImageMagick>=5.2.2:../../graphics/ImageMagick

MAGICK_CONFIG=	${LOCALBASE}/bin/Magick-config

USE_X11=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	LIBS="${LIBS} `${MAGICK_CONFIG} --libs`"
CPPFLAGS+=	`${MAGICK_CONFIG} --cppflags` -DIMAGEMAGICK"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/psiconv
.for file in ascii html html4
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${PREFIX}/share/doc/psiconv
.endfor

.include "../../mk/bsd.pkg.mk"
