# $NetBSD: Makefile,v 1.19 2022/04/17 10:50:30 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	makeindexk-2.15
PKGREVISION=	14
CATEGORIES=	print

HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	General purpose hierarchical index generator

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/makeindexk

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/makeindexk

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
