# $NetBSD: Makefile,v 1.13 2020/05/10 03:56:39 markd Exp $

PKGREVISION= 2
.include "../../print/texlive/Makefile.common"

PKGNAME=	tex4ht-20180225
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Converter from *TeX to HTML, XML, and similar formats
LICENSE=	lppl-1.3c

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/tex4htk

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/tex4htk
USE_TOOLS+=	perl:run
REPLACE_PERL=	mk4ht.pl

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
