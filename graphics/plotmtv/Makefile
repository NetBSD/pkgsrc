# $NetBSD: Makefile,v 1.8 2003/03/29 12:41:20 jmmv Exp $

DISTNAME=	Plotmtv1.4.1
PKGNAME=	plotmtv-1.4.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Multipurpose X11 plotting program

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
