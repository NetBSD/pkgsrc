# $NetBSD: Makefile,v 1.5 2003/07/17 21:27:56 grant Exp $

DISTNAME=	icdprog-0.3
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icdprog/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://icdprog.sourceforge.net/
COMMENT=	Microchip PIC programer using ICD hardware

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icdprog ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
