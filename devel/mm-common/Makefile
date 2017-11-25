# $NetBSD: Makefile,v 1.6 2017/11/25 12:10:05 wiz Exp $

DISTNAME=	mm-common-0.9.11
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/mm-common/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	Provides build infrastructure utilities for GNOME C++ libraries
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gzip pkg-config
USE_LANGUAGES=	c++

PKGCONFIG_OVERRIDE+=	doctags/mm-common-libstdc++-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	doctags/mm-common-libstdc++.pc.in
PKGCONFIG_OVERRIDE+=	skeletonmm/skeleton/skeletonmm-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	skeletonmm/skeleton/skeletonmm.pc.in
PKGCONFIG_OVERRIDE+=	util/mm-common-util.pc.in

.include "../../mk/bsd.pkg.mk"
