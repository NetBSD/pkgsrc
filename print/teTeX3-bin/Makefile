# $NetBSD: Makefile,v 1.80 2015/04/30 10:43:54 markd Exp $

DISTNAME=	teTeX-bin-3.0
PKGREVISION=	59
CATEGORIES=	print
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - binaries

DEPENDS+=	kpathsea>=6.0.0nb2:../../print/kpathsea
DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
DEPENDS+=	teTeX-texmf>=3.0nb14:../../print/teTeX3-texmf
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-metafont-[0-9]*:../../fonts/tex-metafont
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	tex-aleph-[0-9]*:../../print/tex-aleph
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
DEPENDS+=	tex-thumbpdf-[0-9]*:../../print/tex-thumbpdf
DEPENDS+=	web2c>=7.5.7nb2:../../print/web2c

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
