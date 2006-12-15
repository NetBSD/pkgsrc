# $NetBSD: Makefile,v 1.19 2006/12/15 20:32:56 joerg Exp $
#

DISTNAME=		xsoldier-0.96
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.interq.or.jp/libra/oohara/xsoldier/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.interq.or.jp/libra/oohara/xsoldier/
COMMENT=		Updated xgalaga type game with awesome graphics

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

MAKE_ENV+=		BINOWN=${BINOWN:Q}

CONF_FILES_PERMS=	${PREFIX}/share/xsoldier/xsoldier.score.dist	\
			/var/games/xsoldier				\
			games games 0664

post-patch:
	${TOUCH} ${WRKSRC}/xsoldier.man

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
