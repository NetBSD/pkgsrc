# $NetBSD: Makefile,v 1.21 2006/11/05 17:23:45 joerg Exp $

DISTNAME=		libart_lgpl-2.3.17
PKGNAME=		${DISTNAME:S/_lgpl/2/}
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libart_lgpl/2.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.levien.com/libart/
COMMENT=		High-performance 2D graphics library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libart-2.0.pc.in

.include "../../mk/bsd.pkg.mk"
