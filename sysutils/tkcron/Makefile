# $NetBSD: Makefile,v 1.11 2005/01/12 21:05:46 minskim Exp $
#

DISTNAME=	tkcron-2.12
CATEGORIES=	x11 tk
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/alcatel/code/
EXTRACT_SUFX=	.tcl.gz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Graphical frontend to crontab

DEPENDS+=	tk>=8.3.2:../../x11/tk

WRKSRC=		${WRKDIR}
USE_X11=	yes
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} > tkcron.tcl

do-build:
	${SED} -e "\:/usr/local/bin/wish: s;;${LOCALBASE}/bin/wish;g" ${WRKSRC}/tkcron.tcl > ${WRKSRC}/tkcron

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcron ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
