# $NetBSD: Makefile,v 1.12 2004/10/03 00:13:33 tv Exp $
#

DISTNAME=		tvision-0.8
PKGREVISION=		1
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
