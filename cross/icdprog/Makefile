# $NetBSD: Makefile,v 1.11 2020/01/18 23:30:16 rillig Exp $

DISTNAME=	icdprog-0.3
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icdprog/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://icdprog.sourceforge.net/
COMMENT=	Microchip PIC programmer using ICD hardware

WRKSRC=		${WRKDIR}/${DISTNAME}/src

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icdprog ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
