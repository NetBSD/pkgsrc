# $NetBSD: Makefile,v 1.12 2002/06/23 03:54:30 jlam Exp $
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
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin
CFLAGS+=		-I${LOCALBASE}/include -I${X11BASE}/include
CPPFLAGS+=		${CFLAGS}

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${X11PREFIX}/share/xgalaga/README

.include "../../mk/bsd.pkg.mk"
