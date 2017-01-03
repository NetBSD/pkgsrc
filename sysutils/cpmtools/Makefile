# $NetBSD: Makefile,v 1.8 2017/01/03 22:46:53 roy Exp $
#

DISTNAME=		cpmtools-2.13
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.moria.de/~michael/cpmtools/

MAINTAINER=		dgriffi@cs.csubak.edu
HOMEPAGE=		http://www.moria.de/~michael/cpmtools/
COMMENT=		Similar to mtools, except for CP/M filesystems

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share/cpmtools

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALLATION_DIRS+=	bin share/cpmtools ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

# I have no idea why this even wants to link against curses as it appears
# to use neither curses, terminfo or termcap.
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
