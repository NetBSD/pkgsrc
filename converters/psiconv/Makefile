# $NetBSD: Makefile,v 1.19 2002/09/23 20:39:21 jlam Exp $
#

DISTNAME=	psiconv-0.8.2
PKGREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	http://huizen.dds.nl/~frodol/psiconv/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://huizen.dds.nl/~frodol/psiconv/
COMMENT=	PSION 5 file format data conversion utilities

USE_BUILDLINK2=		YES
USE_X11=		YES

GNU_CONFIGURE=		YES
CPPFLAGS+=		-DIMAGEMAGICK

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

DOCDIR=		${PREFIX}/share/doc/psiconv

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/docs; for file in ascii html html4; do		\
		${INSTALL_DATA} $${file} ${DOCDIR};			\
	done

.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
