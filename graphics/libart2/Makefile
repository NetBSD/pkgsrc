# $NetBSD: Makefile,v 1.5 2002/10/19 10:54:54 rh Exp $

DISTNAME=		libart_lgpl-2.3.10
PKGNAME=		${DISTNAME:S/_lgpl/2/}
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libart_lgpl/2.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.levien.com/libart/
COMMENT=		High-performance 2D graphics library

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_X11=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
