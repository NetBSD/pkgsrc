# $NetBSD: Makefile,v 1.5 2003/03/29 12:42:33 jmmv Exp $
#

DISTNAME=	tkcron-2.12
WRKSRC=		${WRKDIR}
CATEGORIES=	x11 tk
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/alcatel/code/
EXTRACT_SUFX=	.tcl.gz

MAINTAINER=	packages@netbsd.org
COMMENT=	graphical frontend to crontab

DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_X11=	yes
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} > tkcron.tcl

do-build:
	${SED} -e "\:/usr/local/bin/wish: s;;${LOCALBASE}/bin/wish;g" ${WRKSRC}/tkcron.tcl > ${WRKSRC}/tkcron

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcron ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
