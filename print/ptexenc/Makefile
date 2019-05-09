# $NetBSD: Makefile,v 1.12 2019/05/09 09:47:36 adam Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	ptexenc-1.3.7
CATEGORIES=	print

HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Library for Japanese pTeX and its tools
LICENSE=	modified-bsd

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/ptexenc

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ptexenc

CONFIGURE_ARGS+=	--with-system-kpathsea
PKGCONFIG_OVERRIDE=	ptexenc.pc.in

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
