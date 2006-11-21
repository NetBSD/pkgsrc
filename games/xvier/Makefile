# $NetBSD: Makefile,v 1.14 2006/11/21 13:40:40 rillig Exp $

DISTNAME=	xvier
PKGNAME=	xvier-1.0
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/strategy/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Four-in-a-row game

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_IMAKE=	YES
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

INSTALLATION_DIRS+=	bin libexec ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xvier ${PREFIX}/bin/xvier
	${INSTALL_PROGRAM} ${WRKSRC}/xvier_prog ${PREFIX}/libexec/xvier_prog
	${INSTALL_MAN} ${WRKSRC}/xvier.man ${PREFIX}/${PKGMANDIR}/man6/xvier.6

.include "../../mk/bsd.pkg.mk"
