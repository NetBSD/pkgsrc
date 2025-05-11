# $NetBSD: Makefile,v 1.6 2025/05/11 02:53:17 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	makejvf-20241229
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asciidwango.github.io/ptex/base/sources.html
COMMENT=	Make Japanese VF file from Japanese TeX TFM file
LICENSE=	modified-bsd

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/makejvf

WRKSRC=	${WRKDIR}/${DISTNAME}/texk/makejvf

CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-ptexenc

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/ptexenc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
