# $NetBSD: Makefile,v 1.3 2002/09/07 03:58:47 rh Exp $

DISTNAME=		libart_lgpl-2.3.10
PKGNAME=		libart2-2.3.10
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.1/sources/libart_lgpl/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.levien.com/libart/
COMMENT=		High-performance 2D graphics library

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_X11BASE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
