# $NetBSD: Makefile,v 1.11 2001/07/09 06:25:31 sakamoto Exp $
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

.include "../../graphics/ImageMagick/buildlink.mk"

USE_X11=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
GNU_CONFIGURE=	YES
CPPFLAGS+=	-DIMAGEMAGICK

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/psiconv
.for file in ascii html html4
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${PREFIX}/share/doc/psiconv
.endfor

.include "../../mk/bsd.pkg.mk"
