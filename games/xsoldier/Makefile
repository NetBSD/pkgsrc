# $NetBSD: Makefile,v 1.9 2001/12/02 06:56:40 jlam Exp $
#

DISTNAME=		xsoldier-0.96
CATEGORIES=		games x11
MASTER_SITES=		http://www.surfline.ne.jp/hachi/xsoldier/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.surfline.ne.jp/hachi/xsoldier.html
COMMENT=		Updated xgalaga type game with awesome graphics

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

MAKE_ENV+=		BINOWN=${BINOWN}

SUPPORT_FILES_PERMS=	${PREFIX}/share/xsoldier/xsoldier.score.dist	\
			/var/games/xsoldier				\
			games games 0664

post-patch:
	${TOUCH} ${WRKSRC}/xsoldier.man

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
