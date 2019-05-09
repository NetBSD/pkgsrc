# $NetBSD: Makefile,v 1.6 2019/05/09 09:47:34 adam Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	afm2pl-0.7.1
PKGREVISION=	5
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Convert an Adobe font metric file to a TeX font property list
LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/afm2pl

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/afm2pl

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
