# $NetBSD: Makefile,v 1.3 2022/06/28 11:35:32 wiz Exp $

DISTNAME=	hyperxmp
PKGNAME=	tex-${DISTNAME}-5.9
PKGREVISION=	2
TEXLIVE_REV=	57004

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hyperxmp
COMMENT=	Embed XMP metadata within a LaTeX document
LICENSE=	lppl-1.3c

USE_TOOLS+=	perl:run
REPLACE_PERL+=	texmf-dist/scripts/hyperxmp/hyperxmp-add-bytecount.pl

# The texlive metadata claims this, but it doesn't exist and isn't
# referred to by the source. XXX?
#DEPENDS+=	tex-hyperxmp.ARCH-[0-9]*:../../print/tex-hyperxmp.ARCH

# Conversely, the texlive metadata does not mention these but the
# package code does use them.
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-ifmtarg-[0-9]*:../../print/tex-ifmtarg
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-intcalc-[0-9]*:../../print/tex-intcalc
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-luacode-[0-9]*:../../print/tex-luacode
DEPENDS+=	tex-pdfescape-[0-9]*:../../print/tex-pdfescape
DEPENDS+=	tex-stringenc-[0-9]*:../../print/tex-stringenc
DEPENDS+=	tex-totpages-[0-9]*:../../print/tex-totpages

#DEPENDS+=	tex-ifthen-[0-9]*:../../print/tex-ifthen
#DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
