# $NetBSD: Makefile,v 1.1.1.1 1999/12/06 01:58:06 sakamoto Exp $
#

DISTNAME=	psiconv-0.6.1
CATEGORIES=	converters
MASTER_SITES=	http://huizen.dds.nl/~frodol/psiconv/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://huizen.dds.nl/~frodol/psiconv/

DEPENDS+=	libgetopt-*:../../devel/libgetopt
DEPENDS+=	ImageMagick-*:../../graphics/ImageMagick

MAGICK_CONFIG=	${LOCALBASE}/bin/Magick-config

USE_X11=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="`${MAGICK_CONFIG} --cppflags` -DIMAGEMAGICK" \
		LIBS="-lgetopt `${MAGICK_CONFIG} --libs`"

post-configure:
	@${RM} -f ${WRKSRC}/libtool
	@${LN} -s ${LIBTOOL} ${WRKSRC}/libtool

post-install:
	${MKDIR} ${PREFIX}/share/doc/psiconv
.for file in ascii html html4
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${PREFIX}/share/doc/psiconv
.endfor

.include "../../mk/bsd.pkg.mk"
