# $NetBSD: Makefile,v 1.12 2004/03/10 00:09:13 snj Exp $
#

DISTNAME=		xbill-2.0
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xbill.org/
COMMENT=		Stop the dreaded Windows virus from infecting computers

CONFLICT=		gnome-games-[0-9]*

USE_BUILDLINK3=		YES
USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/xbill.man ${PREFIX}/man/man6/xbill.6

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
