# $NetBSD: Makefile,v 1.19 2022/04/17 10:34:54 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	dvidvi-1.1
PKGREVISION=	6
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Select and/or rearrange pages in a TeX dvi file

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/dvidvi

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvidvi

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_DEPMETHOD.kpathsea=	build
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
