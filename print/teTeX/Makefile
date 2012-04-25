# $NetBSD: Makefile,v 1.60 2012/04/25 22:17:19 minskim Exp $

DISTNAME=	teTeX-3.0
PKGREVISION=	11
CATEGORIES=	print meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Thomas Esser's TeX distribution for UNIX compatible systems

DEPENDS+=	dviljk-[0-9]*:../../print/dviljk
DEPENDS+=	dvipdfmx-[0-9]*:../../print/dvipdfmx
DEPENDS+=	dvipng-[0-9]*:../../graphics/dvipng
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	gsftopkk-[0-9]*:../../fonts/gsftopkk
DEPENDS+=	ps2pkm-[0-9]*:../../fonts/ps2pkm
DEPENDS+=	teTeX-bin>=3.0nb50:../../print/teTeX3-bin
DEPENDS+=	teTeX-texmf>=3.0nb32:../../print/teTeX3-texmf
DEPENDS+=	tex-a2ping-[0-9]*:../../graphics/tex-a2ping
DEPENDS+=	tex-texdoc-[0-9]*:../../print/tex-texdoc
DEPENDS+=	tex-pdftools-[0-9]*:../../print/tex-pdftools
DEPENDS+=	texi2html>=1.52:../../textproc/texi2html

META_PACKAGE=	yes

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
