# $NetBSD: Makefile,v 1.16 2008/02/04 19:52:55 tnn Exp $

DISTNAME=	vcg.1.30.r3.17
PKGNAME=	vcg-1.30
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Visualization Tool for compiler graphs

WRKSRC=		${WRKDIR}/vcg.1.30
USE_TOOLS+=	imake lex
USE_X11BASE=	yes

pre-patch:
	${MKDIR} ${WRKSRC}/preconf/X11ccNetBSD
	${CP} ${FILESDIR}/conf ${WRKSRC}/preconf/X11ccNetBSD
	${CP} ${FILESDIR}/demo.csh ${WRKSRC}/preconf/X11ccNetBSD
	${CP} ${FILESDIR}/globals.h ${WRKSRC}/preconf/X11ccNetBSD
	${CP} ${FILESDIR}/tMakefile ${WRKSRC}/preconf/X11ccNetBSD
	${MKDIR} ${WRKSRC}/preconf/X11ccDragonFly
	${CP} ${FILESDIR}/conf ${WRKSRC}/preconf/X11ccDragonFly
	${CP} ${FILESDIR}/demo.csh ${WRKSRC}/preconf/X11ccDragonFly
	${CP} ${FILESDIR}/globals.h ${WRKSRC}/preconf/X11ccDragonFly
	${CP} ${FILESDIR}/tMakefile ${WRKSRC}/preconf/X11ccDragonFly

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vcg
	${INSTALL_DATA} ${WRKSRC}/doc/visual.ps  ${PREFIX}/share/doc/vcg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vcg
	${INSTALL_DATA} ${WRKSRC}/expl/*.vcg ${PREFIX}/share/examples/vcg

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
