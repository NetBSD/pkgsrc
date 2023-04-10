# $NetBSD: Makefile,v 1.13 2023/04/10 23:44:59 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	ttfdump-0.5.5
PKGREVISION=	10
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
