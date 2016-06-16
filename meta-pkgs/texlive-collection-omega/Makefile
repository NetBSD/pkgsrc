# $NetBSD: Makefile,v 1.4 2016/06/16 04:03:16 markd Exp $

DISTNAME=	collection-omega
PKGNAME=	texlive-${DISTNAME}-2016
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	30388

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Omega packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-aleph-[0-9]*:../../print/tex-aleph
DEPENDS+=	tex-antomega-[0-9]*:../../print/tex-antomega
DEPENDS+=	tex-lambda-[0-9]*:../../print/tex-lambda
DEPENDS+=	tex-mxedruli-[0-9]*:../../fonts/tex-mxedruli
DEPENDS+=	tex-omega-[0-9]*:../../print/tex-omega
# omegaware is entirely included in web2c
DEPENDS+=	tex-otibet-[0-9]*:../../print/tex-otibet

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
