# $NetBSD: Makefile,v 1.3 2000/03/16 13:02:25 wiz Exp $
# FreeBSD Id: Makefile,v 1.7 1998/08/05 09:31:14 asami Exp $

DISTNAME=	vcg.1.30.r3.17
PKGNAME=	vcg-1.30
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sakamoto@netbsd.org

USE_X11BASE=	yes
WRKSRC=		${WRKDIR}/vcg.1.30

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
