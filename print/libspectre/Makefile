# $NetBSD: Makefile,v 1.19 2013/03/16 22:35:46 dholland Exp $

DISTNAME=	libspectre-0.2.7
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://libspectre.freedesktop.org/releases/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://libspectre.freedesktop.org/wiki/
COMMENT=	Small library for rendering Postscript documents
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=    libspectre.pc.in

.include "../../print/ghostscript/ghostscript.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
