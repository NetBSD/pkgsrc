# $NetBSD: Makefile,v 1.17 2020/05/10 03:56:38 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	dvidvi-1.1
PKGREVISION=	4
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Select and/or rearrange pages in a TeX dvi file

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/dvidvi

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvidvi

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_DEPMETHOD.kpathsea=	build
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
