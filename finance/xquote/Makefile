# $NetBSD: Makefile,v 1.20 2012/10/03 16:10:14 asau Exp $

DISTNAME=		xquote-2.6.10
PKGREVISION=		3
CATEGORIES=		finance x11
MASTER_SITES=		http://xinvest.sunsite.dk/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xinvest.sunsite.dk/xquote.html
COMMENT=		WWW ticker symbol quote retrieval program

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

# needs a symbol that appeared after 4.9.1
BUILDLINK_API_DEPENDS.Xbae+=        Xbae>=4.50

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/Xbae/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
