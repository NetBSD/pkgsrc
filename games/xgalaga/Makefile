# $NetBSD: Makefile,v 1.11 2001/11/29 01:12:33 hubertf Exp $
#

DISTNAME=		xgalaga-2.0.34
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://ogresoft.dyn.ml.org/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://ogresoft.dyn.ml.org/xgal.html
COMMENT=		Very fast true-to-the-original port of galaga for X11

USE_X11BASE=		YES
USE_XPM=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${X11PREFIX}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${X11PREFIX}/bin
CFLAGS+=		-I${X11PREFIX}/include
CPPFLAGS+=		${CFLAGS}

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${X11PREFIX}/share/xgalaga/README

.include "../../mk/bsd.pkg.mk"
