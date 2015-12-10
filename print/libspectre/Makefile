# $NetBSD: Makefile,v 1.25 2015/12/10 12:03:41 markd Exp $

DISTNAME=	libspectre-0.2.7
PKGREVISION=	9
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
