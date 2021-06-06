# $NetBSD: Makefile,v 1.11 2021/06/06 01:17:17 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	ttfdump-0.5.5
PKGREVISION=	8
CATEGORIES=	fonts

HOMEPAGE=	https://www.freetype.org/
COMMENT=	TrueType font dumper
LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/ttfdump

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ttfdump

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
