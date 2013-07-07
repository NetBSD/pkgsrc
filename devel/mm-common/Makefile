# $NetBSD: Makefile,v 1.1 2013/07/07 15:04:28 rodent Exp $

DISTNAME=	mm-common-0.9.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/mm-common/0.9/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	Provides build infrastructure utilities for GNOME C++ libraries
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

PKGCONFIG_OVERRIDE+=	doctags/mm-common-libstdc++-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	doctags/mm-common-libstdc++.pc.in
PKGCONFIG_OVERRIDE+=	skeletonmm/skeleton/skeletonmm-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	skeletonmm/skeleton/skeletonmm.pc.in
PKGCONFIG_OVERRIDE+=	util/mm-common-util.pc.in

.include "../../mk/bsd.pkg.mk"
