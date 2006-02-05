# $NetBSD: Makefile,v 1.14 2006/02/05 23:10:56 joerg Exp $
#

DISTNAME=	tkcron-2.12
PKGREVISION=	1
CATEGORIES=	x11 tk
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/alcatel/code/
EXTRACT_SUFX=	.tcl.gz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Graphical frontend to crontab

DEPENDS+=	tk>=8.3.2:../../x11/tk

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} > tkcron.tcl

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-build:
	${SED} -e "\:/usr/local/bin/wish: s;;${LOCALBASE}/bin/wish;g" ${WRKSRC}/tkcron.tcl > ${WRKSRC}/tkcron

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcron ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
