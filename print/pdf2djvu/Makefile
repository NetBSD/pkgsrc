# $NetBSD: Makefile,v 1.124 2024/11/14 22:21:25 wiz Exp $

DISTNAME=	pdf2djvu-0.9.19
PKGREVISION=	3
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

FORCE_CXX_STD=		c++20 # For poppler-24.10.0

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++17
USE_TOOLS+=		pkg-config gmake intltool msgfmt xgettext

CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--disable-rpath

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
