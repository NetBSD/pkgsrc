# $NetBSD: Makefile,v 1.47 2023/11/12 13:23:18 wiz Exp $

DISTNAME=	libspectre-0.2.9
PKGREVISION=	3
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
