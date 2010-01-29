# $NetBSD: Makefile,v 1.9 2010/01/29 16:55:48 joerg Exp $

DISTNAME=	icdprog-0.3
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icdprog/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icdprog.sourceforge.net/
COMMENT=	Microchip PIC programmer using ICD hardware

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/src

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icdprog ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
