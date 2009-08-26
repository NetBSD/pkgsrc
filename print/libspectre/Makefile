# $NetBSD: Makefile,v 1.3 2009/08/26 19:56:53 sno Exp $

DISTNAME=	libspectre-0.2.2
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://libspectre.freedesktop.org/releases/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://libspectre.freedesktop.org/wiki/
COMMENT=	Small library for rendering Postscript documents

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=    libspectre.pc.in

.include "../../print/ghostscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
