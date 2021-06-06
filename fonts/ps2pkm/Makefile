# $NetBSD: Makefile,v 1.17 2021/06/06 01:17:17 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	ps2pkm-1.8
PKGREVISION=	5
CATEGORIES=	print

HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Tool to convert PostSCript fonts into TeX PK fonts

DEPENDS+=	kpathsea>=6.0.1:../../print/kpathsea

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/ps2pk

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ps2pk

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
