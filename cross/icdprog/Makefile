# $NetBSD: Makefile,v 1.4 2003/06/25 15:22:01 tsarna Exp $

DISTNAME=	icdprog-0.3
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icdprog/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://icdprog.sourceforge.net/
COMMENT=	Microchip PIC programer using ICD hardware

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icdprog ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
