# $NetBSD: Makefile,v 1.2 2003/06/02 01:21:11 jschauma Exp $

DISTNAME=	icdprog-0.3
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icdprog/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://icdprog.sourceforge.net/
COMMENT=	Microchip PIC programer using ICD hardware

WRKSRC=		${WRKDIR}/${DISTNAME}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icdprog ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
