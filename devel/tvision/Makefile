# $NetBSD: Makefile,v 1.22 2013/10/16 20:47:23 roy Exp $
#

DISTNAME=		tvision-0.8
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/c++/}

PATCHFILES=		tvision-0.8-freebsd-patches-20040910.diff.bz2
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sigala.it/sergio/tvision/
COMMENT=		Turbo Vision C++ CUI library for UNIX

MAKE_JOBS_SAFE=		no
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GCC_REQD+=		3.0

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
