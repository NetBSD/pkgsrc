# $NetBSD: Makefile,v 1.1.1.1 2001/08/01 14:56:31 rh Exp $
#

DISTNAME=		jasper-1.500.0
CATEGORIES=		graphics
MASTER_SITES=		http://www.ece.ubc.ca/~mdadams/jasper/software/
EXTRACT_SUFX=		.zip

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ece.ubc.ca/~mdadams/jasper/
COMMENT=		software-based reference implementation of the JPEG-2000 codec

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jasper
.for doc in ChangeLog LICENSE NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/jasper
.endfor

.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
