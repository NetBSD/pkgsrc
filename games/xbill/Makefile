# $NetBSD: Makefile,v 1.9 2001/09/27 23:18:08 jlam Exp $
#

DISTNAME=		xbill-2.0
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xbill.org/
COMMENT=		stop the dreaded Windows virus from infecting computers

CONFLICT=		gnome-games-[0-9]*

USE_IMAKE=		YES
USE_XPM=		YES
NO_INSTALL_MANPAGES=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/xbill.man ${PREFIX}/man/man6/xbill.6

.include "../../mk/bsd.pkg.mk"
