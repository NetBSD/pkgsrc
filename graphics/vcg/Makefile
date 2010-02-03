# $NetBSD: Makefile,v 1.18 2010/02/03 22:22:53 joerg Exp $

DISTNAME=	vcg.1.30.r3.17
PKGNAME=	vcg-1.30
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Visualization Tool for compiler graphs

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

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

INSTALLATION_DIRS+=	share/doc/vcg share/examples/vcg

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/visual.ps ${DESTDIR}${PREFIX}/share/doc/vcg
	${INSTALL_DATA} ${WRKSRC}/expl/*.vcg ${DESTDIR}${PREFIX}/share/examples/vcg

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
