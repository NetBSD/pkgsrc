# $NetBSD: Makefile,v 1.10 2005/09/19 16:37:26 reed Exp $

DISTNAME=	xvier
PKGNAME=	xvier-1.0
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/strategy/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=
COMMENT=	Four-in-a-row game

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_IMAKE=	YES

INSTALLATION_DIRS+=	bin libexec man/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xvier ${PREFIX}/bin/xvier
	${INSTALL_PROGRAM} ${WRKSRC}/xvier_prog ${PREFIX}/libexec/xvier_prog
	${INSTALL_MAN} ${WRKSRC}/xvier._man ${PREFIX}/man/man6/xvier.6

.include "../../mk/bsd.pkg.mk"
