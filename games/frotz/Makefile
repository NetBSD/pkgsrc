# $NetBSD: Makefile,v 1.2 2000/01/15 18:46:28 jlam Exp $
#

DISTNAME=	UnixFrotz232R2Std10
PKGNAME=	frotz-2.32
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.gmd.de/if-archive/infocom/interpreters/frotz/

MAINTAINER=	seebs@plethora.net
HOMEPAGE=	ftp://ftp.gmd.de/if-archive/infocom/interpreters/frotz/

DEPENDS+=	ncurses>=4.2:../../devel/ncurses

WRKSRC=		${WRKDIR}/frotz-2.32

post-install:
		cd ${WRKSRC}; \
		${INSTALL_MAN} frotz.6 ${PREFIX}/man/man6/

.include "../../mk/bsd.pkg.mk"
