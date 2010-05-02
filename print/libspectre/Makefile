# $NetBSD: Makefile,v 1.8 2010/05/02 11:53:14 wiz Exp $

DISTNAME=	libspectre-0.2.5
CATEGORIES=	print
MASTER_SITES=	http://libspectre.freedesktop.org/releases/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://libspectre.freedesktop.org/wiki/
COMMENT=	Small library for rendering Postscript documents
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=    libspectre.pc.in

.include "../../print/ghostscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
