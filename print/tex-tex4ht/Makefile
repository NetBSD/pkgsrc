# $NetBSD: Makefile,v 1.16 2019/12/06 20:23:26 markd Exp $

DISTNAME=	tex4ht
PKGNAME=	tex-${DISTNAME}-2019.51746
TEXLIVE_REV=	51746

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tex4ht
COMMENT=	Convert (La)TeX to HTML/XML
LICENSE=	lppl-1.3c

DEPENDS+=	tex4ht-[0-9]*:../../print/tex4ht

#TEXLIVE_IGNORE_PATTERNS=	texmf-dist/scripts

post-patch:
	rm ${WRKDIR}/texmf-dist/scripts/tex4ht/*.sh
	rm ${WRKDIR}/texmf-dist/scripts/tex4ht/mk4ht.pl

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
