# $NetBSD: Makefile,v 1.3 2000/05/13 01:15:01 wiz Exp $
#

DISTNAME=	psiconv-0.6.1
CATEGORIES=	converters
MASTER_SITES=	http://huizen.dds.nl/~frodol/psiconv/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://huizen.dds.nl/~frodol/psiconv/

.if !exists(/usr/include/getopt.h)
DEPENDS+=	libgetopt-[0-9]*:../../devel/libgetopt
LIBS=		-lgetopt
.endif
DEPENDS+=	ImageMagick-*:../../graphics/ImageMagick

MAGICK_CONFIG=	${LOCALBASE}/bin/Magick-config

USE_X11=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="`${MAGICK_CONFIG} --cppflags` -DIMAGEMAGICK" \
		LIBS="${LIBS} `${MAGICK_CONFIG} --libs`"

post-configure:
	@${RM} -f ${WRKSRC}/libtool
	@${LN} -s ${LIBTOOL} ${WRKSRC}/libtool

post-install:
	${MKDIR} ${PREFIX}/share/doc/psiconv
.for file in ascii html html4
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${PREFIX}/share/doc/psiconv
.endfor

.include "../../mk/bsd.pkg.mk"
