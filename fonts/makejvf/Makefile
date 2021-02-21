# $NetBSD: Makefile,v 1.1 2021/02/21 06:28:38 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	makejvf-1.1a
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
