# $NetBSD: Makefile,v 1.1 1998/08/01 13:25:28 frueauf Exp $
#

DISTNAME=		xgalaga-2.0.34
CATEGORIES=		games x11
MASTER_SITES=		http://ogresoft.dyn.ml.org/

MAINTAINER=		root@garbled.net

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${X11BASE}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${X11BASE}/bin

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${X11BASE}/share/xgalaga/README

.include "../../mk/bsd.pkg.mk"
