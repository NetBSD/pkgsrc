# $NetBSD: Makefile,v 1.16 2021/06/06 01:17:19 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	tex4ht-20180703
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
