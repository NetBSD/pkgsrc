# $NetBSD: Makefile,v 1.13 2005/04/11 21:45:59 tv Exp $
#

DISTNAME=		xsoldier-0.96
CATEGORIES=		games x11
MASTER_SITES=		http://www.surfline.ne.jp/hachi/xsoldier/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.surfline.ne.jp/hachi/xsoldier.html
COMMENT=		Updated xgalaga type game with awesome graphics

USE_PKGINSTALL=		YES
USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

MAKE_ENV+=		BINOWN=${BINOWN}

SUPPORT_FILES_PERMS=	${PREFIX}/share/xsoldier/xsoldier.score.dist	\
			/var/games/xsoldier				\
			games games 0664

post-patch:
	${TOUCH} ${WRKSRC}/xsoldier.man

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
