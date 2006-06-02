# $NetBSD: Makefile,v 1.16 2006/06/02 18:15:05 joerg Exp $
#

DISTNAME=		tvision-0.8
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/c++/}

PATCHFILES=		tvision-0.8-freebsd-patches-20040910.diff.bz2
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sigala.it/sergio/tvision/
COMMENT=		Turbo Vision C++ CUI library for UNIX

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c++
USE_LIBTOOL=		YES
GCC_REQD+=		3.0

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
