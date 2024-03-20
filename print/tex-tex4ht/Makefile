# $NetBSD: Makefile,v 1.23 2024/03/20 11:19:37 markd Exp $

DISTNAME=	tex4ht
PKGNAME=	tex-${DISTNAME}-2024
TEXLIVE_REV=	70613

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tex4ht
COMMENT=	Convert (La)TeX to HTML/XML
LICENSE=	lppl-1.3c

DEPENDS+=	tex4ht-[0-9]*:../../print/tex4ht

post-patch:
	rm ${WRKDIR}/texmf-dist/scripts/tex4ht/*.sh
	rm ${WRKDIR}/texmf-dist/scripts/tex4ht/mk4ht.pl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
