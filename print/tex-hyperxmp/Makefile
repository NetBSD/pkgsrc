# $NetBSD: Makefile,v 1.6 2024/02/04 00:24:28 markd Exp $

DISTNAME=	hyperxmp
PKGNAME=	tex-${DISTNAME}-5.12
TEXLIVE_REV=	68251

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hyperxmp
COMMENT=	Embed XMP metadata within a LaTeX document
LICENSE=	lppl-1.3c

USE_TOOLS+=	perl:run
REPLACE_PERL+=	texmf-dist/scripts/hyperxmp/hyperxmp-add-bytecount.pl

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-ifmtarg-[0-9]*:../../print/tex-ifmtarg
# ifluatex
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
# ifthen
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-intcalc-[0-9]*:../../print/tex-intcalc
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-luacode-[0-9]*:../../print/tex-luacode
DEPENDS+=	tex-pdfescape-[0-9]*:../../print/tex-pdfescape
DEPENDS+=	tex-stringenc-[0-9]*:../../print/tex-stringenc
DEPENDS+=	tex-totpages-[0-9]*:../../print/tex-totpages

INSTALLATION_DIRS+=	bin

post-install:
	${LN} -sf ${PREFIX}/share/texmf-dist/scripts/hyperxmp/hyperxmp-add-bytecount.pl ${DESTDIR}${PREFIX}/bin/hyperxmp-add-bytecount

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
