# $NetBSD: Makefile,v 1.6 2009/07/07 15:28:47 joerg Exp $
#

DISTNAME=		rexima-1.4
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.ibiblio.org/pub/Linux/apps/sound/mixers/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rus.members.beeb.net/rexima.html
COMMENT=		Curses-based interactive mixer

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
