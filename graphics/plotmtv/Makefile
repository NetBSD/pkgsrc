# $NetBSD: Makefile,v 1.12 2004/07/21 21:16:10 salo Exp $

DISTNAME=	Plotmtv1.4.1
PKGNAME=	plotmtv-1.4.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Multipurpose X11 plotting program

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_IMAKE=	yes

post-extract:
	@${MV} -f ${WRKSRC}/Docs/plotmtv.man ${WRKSRC}/Plot

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/plotmtv
	${INSTALL_DATA} ${WRKSRC}/Tests/*.mtv ${PREFIX}/share/examples/plotmtv
	${INSTALL_SCRIPT} ${WRKSRC}/Tests/run.sh ${WRKSRC}/Tests/run.csh \
		${PREFIX}/share/examples/plotmtv

.include "../../mk/bsd.pkg.mk"
