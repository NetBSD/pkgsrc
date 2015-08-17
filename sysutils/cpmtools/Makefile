# $NetBSD: Makefile,v 1.6 2015/08/17 17:11:29 wiz Exp $
#

DISTNAME=		cpmtools-2.13
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.moria.de/~michael/cpmtools/

MAINTAINER=		dgriffi@cs.csubak.edu
HOMEPAGE=		http://www.moria.de/~michael/cpmtools/
COMMENT=		Similar to mtools, except for CP/M filesystems

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share/cpmtools

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALLATION_DIRS+=	bin share/cpmtools ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
