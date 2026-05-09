# $NetBSD: Makefile,v 1.1 2026/05/09 14:07:30 wiz Exp $

DISTNAME=	xnecview-1.37
CATEGORIES=	ham
MASTER_SITES=	https://www.pa3fwm.nl/software/xnecview/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ea1abz@gmail.com
HOMEPAGE=	https://www.pa3fwm.nl/software/xnecview/
COMMENT=	Program for visualizing NEC input and output files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xnecview \
		${DESTDIR}${PREFIX}/bin/xnecview
	${INSTALL_MAN} ${WRKSRC}/xnecview.1x \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xnecview.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
