# $NetBSD: Makefile,v 1.14 2020/05/10 03:56:39 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	ptexenc-1.3.8
CATEGORIES=	print

HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Library for Japanese pTeX and its tools
LICENSE=	modified-bsd

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/ptexenc

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ptexenc

CONFIGURE_ARGS+=	--with-system-kpathsea
PKGCONFIG_OVERRIDE=	ptexenc.pc.in

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
