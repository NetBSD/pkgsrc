# $NetBSD: Makefile,v 1.2 1998/08/20 15:16:59 tsarna Exp $
#

DISTNAME=		xsoldier-0.96
CATEGORIES=		games x11
MASTER_SITES=		http://www.surfline.ne.jp/hachi/xsoldier/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.surfline.ne.jp/hachi/xsoldier.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	${TOUCH} ${WRKSRC}/xsoldier.man

.include "../../mk/bsd.pkg.mk"
