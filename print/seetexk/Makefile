# $NetBSD: Makefile,v 1.9 2021/06/06 01:17:19 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	seetexk-20200908
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Utilities for manipulating DVI files
LICENSE=	x11

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/seetexk

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/seetexk

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
