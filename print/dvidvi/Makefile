# $NetBSD: Makefile,v 1.21 2024/03/21 08:14:00 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	dvidvi-1.1
PKGREVISION=	8
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Select and/or rearrange pages in a TeX dvi file

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/dvidvi

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvidvi

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_DEPMETHOD.kpathsea=	build
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
