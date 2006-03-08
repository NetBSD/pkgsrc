# $NetBSD: Makefile,v 1.1.1.1 2006/03/08 08:42:04 ghen Exp $

DISTNAME=	dd_rescue-1.11
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://www.garloff.de/kurt/linux/ddrescue/
COMMENT=	dd(1)-like tool for rescuing data from media with errors

WRKSRC=		${WRKDIR}/dd_rescue

BUILD_TARGET=	dd_rescue

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/dd_rescue ${PREFIX:Q}/bin/

.include "../../mk/bsd.pkg.mk"
