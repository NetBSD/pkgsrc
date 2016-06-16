# $NetBSD: Makefile,v 1.5 2016/06/16 04:03:15 markd Exp $

DISTNAME=	collection-langpolish
PKGNAME=	texlive-${DISTNAME}-2016pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	30372

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Polish TeX packages

DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex
DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-babel-polish-[0-9]*:../../print/tex-babel-polish
# depend cc-pl
DEPENDS+=	tex-gustlib-[0-9]*:../../print/tex-gustlib
# gustprog is documentation only
DEPENDS+=	tex-hyphen-polish-[0-9]*:../../print/tex-hyphen-polish
# lshort-polish is documentation only
# depend mex
# depend mwcls
DEPENDS+=	tex-pl-[0-9]*:../../fonts/tex-pl
# depend polski
# depend przechlewski-book
# depend qpxqtx
# depend tap
# tex-virtual-academy-pl is documentation only
# texlive-pl is documentation only
# depend utf8mex

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
