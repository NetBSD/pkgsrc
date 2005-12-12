# $NetBSD: Makefile,v 1.13 2005/12/12 21:36:54 joerg Exp $

DISTNAME=		xquote-2.6.10
PKGREVISION=		1
CATEGORIES=		finance x11
MASTER_SITES=		http://xinvest.sunsite.dk/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://xinvest.sunsite.dk/xquote.html
COMMENT=		WWW ticker symbol quote retrieval program

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

# needs a symbol that appeared after 4.9.1
BUILDLINK_DEPENDS.Xbae+=        Xbae>=4.50

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/Xbae/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
