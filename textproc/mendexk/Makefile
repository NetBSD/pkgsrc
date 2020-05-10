# $NetBSD: Makefile,v 1.14 2020/05/10 03:56:40 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	mendexk-3.2
CATEGORIES=	textproc

HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Replacement for makeindex with many enhancements
LICENSE=	modified-bsd

CONFLICTS+=	ja-ptex-bin-[0-9]*

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/mendexk

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/mendexk

CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-ptexenc

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
BUILDLINK_API_DEPENDS.ptexenc+= ptexenc>=1.3.3
.include "../../print/ptexenc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
