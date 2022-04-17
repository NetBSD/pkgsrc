# $NetBSD: Makefile,v 1.19 2022/04/17 10:35:41 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	dviljk-2.6.5
PKGREVISION=	13
CATEGORIES=	print

HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	DVI driver for the LaserJet printers using kpathsea

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/dviljk

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dviljk

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
