# $NetBSD: Makefile,v 1.3 1999/01/30 23:18:49 agc Exp $
#

DISTNAME=		xgalaga-2.0.34
CATEGORIES=		games x11
MASTER_SITES=		http://ogresoft.dyn.ml.org/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://ogresoft.dyn.ml.org/xgal.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${X11BASE}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${X11BASE}/bin

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${X11BASE}/share/xgalaga/README

.include "../../mk/bsd.pkg.mk"
