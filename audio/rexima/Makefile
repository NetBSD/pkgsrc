# $NetBSD: Makefile,v 1.1.1.1 2004/10/23 09:24:54 wiz Exp $
#

DISTNAME=		rexima-1.4
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.ibiblio.org/pub/Linux/apps/sound/mixers/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://rus.members.beeb.net/rexima.html
COMMENT=		Curses-based interactive mixer

USE_BUILDLINK3=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
