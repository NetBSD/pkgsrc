# $NetBSD: Makefile,v 1.1.1.1 2006/11/30 12:04:16 obache Exp $
#

DISTNAME=		cpmtools-2.5
CATEGORIES=		sysutils
MASTER_SITES=		http://www.moria.de/~michael/cpmtools/

MAINTAINER=		dgriffi@cs.csubak.edu
HOMEPAGE=		http://www.moria.de/~michael/cpmtools/
COMMENT=		Similar to mtools, except for CP/M filesystems

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/cpmtools

INSTALLATION_DIRS+=	share/cpmtools

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
