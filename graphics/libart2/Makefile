# $NetBSD: Makefile,v 1.10 2003/09/08 15:28:38 adam Exp $

DISTNAME=		libart_lgpl-2.3.15
PKGNAME=		${DISTNAME:S/_lgpl/2/}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libart_lgpl/2.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.levien.com/libart/
COMMENT=		High-performance 2D graphics library

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_X11=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
