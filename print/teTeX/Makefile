# $NetBSD: Makefile,v 1.57 2010/02/18 15:23:24 gdt Exp $

DISTNAME=	teTeX-3.0
PKGREVISION=	9
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
DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin
DEPENDS+=	teTeX-texmf-[0-9]*:../../print/teTeX3-texmf
DEPENDS+=	tex-a2ping-[0-9]*:../../graphics/tex-a2ping
DEPENDS+=	texi2html>=1.52:../../textproc/texi2html
DEPENDS+=	texlive-pdftools-[0-9]*:../../print/texlive-pdftools
DEPENDS+=	xdvik-[0-9]*:../../print/xdvik

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
