# $NetBSD: Makefile,v 1.16 2008/07/14 12:56:03 joerg Exp $

DISTNAME=		xinvest-2.6.9
PKGREVISION=		2
CATEGORIES=		finance x11
MASTER_SITES=		http://xinvest.sunsite.dk/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xinvest.sunsite.dk/xinvest.html
COMMENT=		Personal finance tracking and performance tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
