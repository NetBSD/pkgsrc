# $NetBSD: Makefile,v 1.21 2025/01/06 21:49:16 ktnb Exp $
#

DISTNAME=	pag-0.92
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://pancake.host.sk/
COMMENT=	Platform Arcade Game

USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
