# $NetBSD: Makefile,v 1.7 2015/05/05 20:31:18 wiz Exp $

DISTNAME=	texlive-en.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	36087

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX Live manual (English)

DEPENDS+=	tex-texlive-common-doc>=2013nb1:../../print/tex-texlive-common-doc

INFO_FILES=	tlbuild.info

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
