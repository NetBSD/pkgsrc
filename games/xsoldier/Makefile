# $NetBSD: Makefile,v 1.5 2001/06/30 11:56:20 zuntum Exp $
#

DISTNAME=		xsoldier-0.96
CATEGORIES=		games x11
MASTER_SITES=		http://www.surfline.ne.jp/hachi/xsoldier/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.surfline.ne.jp/hachi/xsoldier.html
COMMENT=		Updated xgalaga type game with awesome graphics

USE_BUILDLINK_ONLY=	YES
USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

post-patch:
	${TOUCH} ${WRKSRC}/xsoldier.man

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
