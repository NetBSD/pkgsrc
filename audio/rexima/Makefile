# $NetBSD: Makefile,v 1.11 2017/01/04 16:59:28 roy Exp $
#

DISTNAME=		rexima-1.4
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.ibiblio.org/pub/Linux/apps/sound/mixers/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rus.members.beeb.net/rexima.html
COMMENT=		Curses-based interactive mixer
LICENSE=		gnu-gpl-v2

FAKE_NCURSES=		yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
