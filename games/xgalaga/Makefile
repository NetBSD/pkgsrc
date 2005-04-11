# $NetBSD: Makefile,v 1.20 2005/04/11 21:45:58 tv Exp $

DISTNAME=		xgalaga-2.0.34
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		root@garbled.net
COMMENT=		Very fast true-to-the-original port of galaga for X11

NO_SRC_ON_FTP=		"already in MASTER_SITE_LOCAL"

USE_X11=		YES
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin

WRKSRC=			${WRKDIR}/${PKGNAME:C,nb${PKGREVISION},,}

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/xgalaga/README

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
