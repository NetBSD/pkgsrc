# $NetBSD: Makefile,v 1.1.1.1 2003/05/28 16:10:46 tsarna Exp $

DISTNAME=	icdprog-0.3
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icdprog/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://icdprog.sourceforge.net/
COMMENT=	Microchip PIC programer using ICD hardware

WRKSRC=		${WRKDIR}/${DISTNAME}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icdprog ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
