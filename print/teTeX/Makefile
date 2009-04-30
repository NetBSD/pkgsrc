# $NetBSD: Makefile,v 1.52 2009/04/30 01:01:41 minskim Exp $

DISTNAME=	teTeX-3.0
PKGREVISION=	6
CATEGORIES=	print meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Thomas Esser's TeX distribution for UNIX compatible systems

DEPENDS+=	dviljk-[0-9]*:../../print/dviljk
DEPENDS+=	dvipdfm-[0-9]*:../../print/dvipdfm
DEPENDS+=	dvipng-[0-9]*:../../graphics/dvipng
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin
DEPENDS+=	teTeX-texmf-[0-9]*:../../print/teTeX3-texmf
DEPENDS+=	texi2html>=1.52:../../textproc/texi2html
DEPENDS+=	xdvik-[0-9]*:../../print/xdvik

CONFLICTS+=	teTeX2-[0-9]*

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
