# $NetBSD: Makefile,v 1.13 2025/11/17 11:00:30 wiz Exp $

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
