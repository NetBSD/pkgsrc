# $NetBSD: Makefile,v 1.3 2001/02/16 15:22:30 wiz Exp $

DISTNAME=	Plotmtv1.4.1
PKGNAME=	plotmtv-1.4.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jtb@netbsd.org
COMMENT=	Multipurpose X11 plotting program

WRKSRC=		${WRKDIR}/Plotmtv1.4.1

USE_IMAKE=	YES
USE_X11_BASE=	YES

post-extract:
	@${MV} -f ${WRKSRC}/Docs/plotmtv.man ${WRKSRC}/Plot

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/plotmtv
	${INSTALL_DATA} ${WRKSRC}/Tests/*.mtv ${PREFIX}/share/examples/plotmtv
	${INSTALL_SCRIPT} ${WRKSRC}/Tests/run.sh ${WRKSRC}/Tests/run.csh \
	${PREFIX}/share/examples/plotmtv

.include "../../mk/bsd.pkg.mk"
