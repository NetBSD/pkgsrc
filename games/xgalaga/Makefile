# $NetBSD: Makefile,v 1.13 2002/10/21 12:16:29 wiz Exp $
#

DISTNAME=		xgalaga-2.0.34
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		# http://ogresoft.dyn.ml.org/

MAINTAINER=		root@garbled.net
# HOMEPAGE=		http://ogresoft.dyn.ml.org/xgal.html
COMMENT=		Very fast true-to-the-original port of galaga for X11

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${X11PREFIX}/share/xgalaga/README

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
