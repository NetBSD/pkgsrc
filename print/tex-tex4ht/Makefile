# $NetBSD: Makefile,v 1.11 2019/02/01 22:42:55 markd Exp $

DISTNAME=	tex4ht
PKGNAME=	tex-${DISTNAME}-2018.49879
TEXLIVE_REV=	49879

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tex4ht
COMMENT=	Convert (La)TeX to HTML/XML
LICENSE=	lppl-1.3c

DEPENDS+=	tex4ht-[0-9]*:../../print/tex4ht

#TEXLIVE_IGNORE_PATTERNS=	texmf-dist/scripts

post-patch:
	rm ${WRKDIR}/texmf-dist/scripts/tex4ht/*.sh
	rm ${WRKDIR}/texmf-dist/scripts/tex4ht/mk4ht.pl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
