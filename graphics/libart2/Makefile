# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:46:33 jlam Exp $

DISTNAME=		libart_lgpl-2.3.8
PKGNAME=		libart2-2.3.8
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=pre-gnome2/sources/libart_lgpl/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.levien.com/libart/
COMMENT=		High-performance 2D graphics library

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
