# $NetBSD: Makefile,v 1.7 2004/02/21 06:44:26 snj Exp $

DISTNAME=	icdprog-0.3
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icdprog/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://icdprog.sourceforge.net/
COMMENT=	Microchip PIC programmer using ICD hardware

WRKSRC=		${WRKDIR}/${DISTNAME}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icdprog ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
