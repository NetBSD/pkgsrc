# $NetBSD: Makefile,v 1.2 2006/10/19 07:26:06 ghen Exp $

DISTNAME=	dd_rescue-1.12
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://www.garloff.de/kurt/linux/ddrescue/
COMMENT=	dd(1)-like tool for rescuing data from media with errors

WRKSRC=		${WRKDIR}/dd_rescue

BUILD_TARGET=	dd_rescue

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/dd_rescue ${PREFIX:Q}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC:Q}/README.dd_rescue ${PREFIX}/share/doc/${PKGBASE}/README

.include "../../mk/bsd.pkg.mk"
