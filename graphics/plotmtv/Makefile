# $NetBSD: Makefile,v 1.7 2003/03/02 19:47:24 jschauma Exp $

DISTNAME=	Plotmtv1.4.1
PKGNAME=	plotmtv-1.4.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Multipurpose X11 plotting program

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_IMAKE=	yes
USE_X11BASE=	yes

post-extract:
	@${MV} -f ${WRKSRC}/Docs/plotmtv.man ${WRKSRC}/Plot

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/plotmtv
	${INSTALL_DATA} ${WRKSRC}/Tests/*.mtv ${PREFIX}/share/examples/plotmtv
	${INSTALL_SCRIPT} ${WRKSRC}/Tests/run.sh ${WRKSRC}/Tests/run.csh \
		${PREFIX}/share/examples/plotmtv

.include "../../mk/bsd.pkg.mk"
