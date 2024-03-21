# $NetBSD: Makefile,v 1.14 2024/03/21 08:00:34 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	lcdftypetools-2.110
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lcdf-typetools
COMMENT=	Outline font manipulation tools
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/lcdf-typetools

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/lcdf-typetools

USE_LANGUAGES=		c c++11
CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
