# $NetBSD: Makefile,v 1.4 2001/12/06 04:03:01 jlam Exp $

DISTNAME=		xmris.4.04
PKGNAME=		xmris-4.04
CATEGORIES=		games x11
MASTER_SITES=		http://www.cs.bris.ac.uk/~nathan/xmris/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.cs.bris.ac.uk/~nathan/xmris/
COMMENT=		Version of the Mr Do video arcade game for X

USE_IMAKE=		yes
ALL_TARGET=		initialize xmris xmred
NO_INSTALL_MANPAGES=	yes

OWN_DIRS_PERMS=		/var/games/${PKGBASE} games games 775

post-install:
	${INSTALL_MAN} ${WRKSRC}/xmris.man ${PREFIX}/man/man6/xmris.6
	${LN} -fs xmris.6 ${PREFIX}/man/man6/xmsit.6
	${INSTALL_MAN} ${WRKSRC}/xmred.man ${PREFIX}/man/man6/xmred.6

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
