# $NetBSD: Makefile,v 1.8 2005/03/24 21:12:55 wiz Exp $

DISTNAME=	vcg.1.30.r3.17
PKGNAME=	vcg-1.30
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sakamoto@NetBSD.org
COMMENT=	Visualization Tool for compiler graphs

WRKSRC=		${WRKDIR}/vcg.1.30
USE_X11BASE=	yes

pre-patch:
	@${MKDIR} ${WRKSRC}/preconf/X11ccNetBSD
	@${CP} ${FILESDIR}/conf ${WRKSRC}/preconf/X11ccNetBSD
	@${CP} ${FILESDIR}/demo.csh ${WRKSRC}/preconf/X11ccNetBSD
	@${CP} ${FILESDIR}/globals.h ${WRKSRC}/preconf/X11ccNetBSD
	@${CP} ${FILESDIR}/tMakefile ${WRKSRC}/preconf/X11ccNetBSD

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vcg
	${INSTALL_DATA} ${WRKSRC}/doc/visual.ps  ${PREFIX}/share/doc/vcg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vcg
	${INSTALL_DATA} ${WRKSRC}/expl/*.vcg ${PREFIX}/share/examples/vcg

.include "../../mk/bsd.pkg.mk"
