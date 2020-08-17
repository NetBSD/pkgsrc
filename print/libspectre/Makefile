# $NetBSD: Makefile,v 1.45 2020/08/17 20:17:40 leot Exp $

DISTNAME=	libspectre-0.2.9
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://libspectre.freedesktop.org/releases/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/libspectre/
COMMENT=	Small library for rendering Postscript documents
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libspectre.pc.in

BUILDLINK_API_DEPENDS.ghostscript-agpl+=	ghostscript-agpl>=9.24
.include "../../print/ghostscript-agpl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
