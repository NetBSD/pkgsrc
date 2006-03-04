# $NetBSD: Makefile,v 1.8 2006/03/04 21:29:07 jlam Exp $

DISTNAME=	icdprog-0.3
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icdprog/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icdprog.sourceforge.net/
COMMENT=	Microchip PIC programmer using ICD hardware

WRKSRC=		${WRKDIR}/${DISTNAME}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icdprog ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
