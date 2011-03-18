# $NetBSD: Makefile,v 1.18 2011/03/18 20:47:06 zafer Exp $
#

DISTNAME=	tkcron-2.12
PKGREVISION=	1
CATEGORIES=	x11 tk
MASTER_SITES=	# ftp://ftp.neosoft.com/languages/tcl/alcatel/code/
EXTRACT_SUFX=	.tcl.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphical frontend to crontab

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	tk>=8.3.2:../../x11/tk

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} > tkcron.tcl

INSTALLATION_DIRS=	bin

do-build:
	${SED} -e "\:/usr/local/bin/wish: s;;${LOCALBASE}/bin/wish;g" ${WRKSRC}/tkcron.tcl > ${WRKSRC}/tkcron

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcron ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
