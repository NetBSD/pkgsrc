# $NetBSD: Makefile,v 1.4 2000/07/11 08:43:53 agc Exp $
#

DISTNAME=		xgalaga-2.0.34
CATEGORIES=		games x11
MASTER_SITES=		http://ogresoft.dyn.ml.org/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://ogresoft.dyn.ml.org/xgal.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${X11PREFIX}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${X11PREFIX}/bin

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${X11PREFIX}/share/xgalaga/README

.include "../../mk/bsd.pkg.mk"
