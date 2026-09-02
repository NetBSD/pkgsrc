# $NetBSD: Makefile,v 1.138 2026/09/02 19:04:10 wiz Exp $

DISTNAME=	pdf2djvu-0.9.19
PKGREVISION=	17
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=jwilk/}
GITHUB_PROJECT=	pdf2djvu
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://jwilk.net/software/pdf2djvu
COMMENT=	Creates DjVu files from PDF files
LICENSE=	gnu-gpl-v2

DEPENDS+=	djvulibre-tools-[0-9]*:../../graphics/djvulibre-tools

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++
USE_CXX_FEATURES=	c++20
FORCE_CXX_STD=		c++20 # For poppler-24.10.0

USE_TOOLS+=		pkg-config gmake intltool msgfmt xgettext

CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

CFLAGS+=		-fno-permissive

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
