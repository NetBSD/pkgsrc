# $NetBSD: Makefile,v 1.11 2018/06/17 14:37:00 wiz Exp $

DISTNAME=	pdf2svg-0.2.3
PKGREVISION=	10
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=dawbarton/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsd@cs.ubc.ca
HOMEPAGE=	http://www.cityinthesky.co.uk/opensource/pdf2svg/
COMMENT=	Small utility to convert PDF files to SVG files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

BUILD_TARGET=	pdf2svg

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
