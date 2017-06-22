# $NetBSD: Makefile,v 1.8 2017/06/22 09:37:22 markd Exp $

DISTNAME=	collection-langpolish
PKGNAME=	texlive-${DISTNAME}-2017pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	44371

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Polish TeX packages

DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex
DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-babel-polish-[0-9]*:../../print/tex-babel-polish
# depend bredzenie
DEPENDS+=	tex-cc-pl-[0-9]*:../../fonts/tex-cc-pl
DEPENDS+=	tex-gustlib-[0-9]*:../../print/tex-gustlib
# gustprog is documentation only
DEPENDS+=	tex-hyphen-polish-[0-9]*:../../print/tex-hyphen-polish
# lshort-polish is documentation only
DEPENDS+=	tex-mex-[0-9]*:../../print/tex-mex
DEPENDS+=	tex-mwcls-[0-9]*:../../print/tex-mwcls
DEPENDS+=	tex-pl-[0-9]*:../../fonts/tex-pl
DEPENDS+=	tex-polski-[0-9]*:../../print/tex-polski
DEPENDS+=	tex-przechlewski-book-[0-9]*:../../print/tex-przechlewski-book
DEPENDS+=	tex-qpxqtx-[0-9]*:../../fonts/tex-qpxqtx
DEPENDS+=	tex-tap-[0-9]*:../../print/tex-tap
# tex-virtual-academy-pl is documentation only
# texlive-pl is documentation only
DEPENDS+=	tex-utf8mex-[0-9]*:../../print/tex-utf8mex

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
