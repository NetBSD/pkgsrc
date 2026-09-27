# $NetBSD: Makefile,v 1.67 2026/09/27 11:35:19 tnn Exp $

DISTNAME=	pdf2svg-0.2.4
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=dawbarton/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsd@cs.ubc.ca
HOMEPAGE=	https://cityinthesky.co.uk/opensource/pdf2svg/
COMMENT=	Small utility to convert PDF files to SVG files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

BUILD_TARGET=	pdf2svg

BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
