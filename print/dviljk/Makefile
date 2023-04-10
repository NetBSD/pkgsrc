# $NetBSD: Makefile,v 1.20 2023/04/10 23:46:39 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	dviljk-2.6.5
PKGREVISION=	14
CATEGORIES=	print

HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	DVI driver for the LaserJet printers using kpathsea

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/dviljk

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dviljk

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
