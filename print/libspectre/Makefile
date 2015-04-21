# $NetBSD: Makefile,v 1.24 2015/04/21 22:28:36 rodent Exp $

DISTNAME=	libspectre-0.2.7
PKGREVISION=	8
CATEGORIES=	print
MASTER_SITES=	http://libspectre.freedesktop.org/releases/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/libspectre/
COMMENT=	Small library for rendering Postscript documents
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=    libspectre.pc.in

.include "../../print/ghostscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
