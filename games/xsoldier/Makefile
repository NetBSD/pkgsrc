# $NetBSD: Makefile,v 1.17 2006/02/05 23:09:25 joerg Exp $
#

DISTNAME=		xsoldier-0.96
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.surfline.ne.jp/hachi/xsoldier/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.surfline.ne.jp/hachi/xsoldier.html
COMMENT=		Updated xgalaga type game with awesome graphics

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

MAKE_ENV+=		BINOWN=${BINOWN:Q}

CONF_FILES_PERMS=	${PREFIX}/share/xsoldier/xsoldier.score.dist	\
			/var/games/xsoldier				\
			games games 0664

post-patch:
	${TOUCH} ${WRKSRC}/xsoldier.man

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
