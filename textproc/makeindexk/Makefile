# $NetBSD: Makefile,v 1.16 2020/01/18 23:35:29 rillig Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	makeindexk-2.15
PKGREVISION=	11
CATEGORIES=	print

HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	General purpose hierarchical index generator

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/makeindexk

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/makeindexk

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
