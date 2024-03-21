# $NetBSD: Makefile,v 1.12 2024/03/21 07:56:08 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	afm2pl-0.7.1
PKGREVISION=	10
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Convert an Adobe font metric file to a TeX font property list
LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/afm2pl

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/afm2pl

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
