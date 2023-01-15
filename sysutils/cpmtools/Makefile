# $NetBSD: Makefile,v 1.9 2023/01/15 15:41:46 thorpej Exp $
#

DISTNAME=		cpmtools-2.23
CATEGORIES=		sysutils
MASTER_SITES=		http://www.moria.de/~michael/cpmtools/files/

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
