# $NetBSD: Makefile,v 1.11 2004/09/10 19:32:44 wiz Exp $
#

DISTNAME=		tvision-0.8
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/c++/}

PATCHFILES=		tvision-0.8-freebsd-patches-20040910.diff.bz2
PATCH_DIST_STRIP=	-p1

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.sigala.it/sergio/tvision/
COMMENT=		Turbo Vision C++ CUI library for UNIX

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
GCC_REQD=		3.0

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
