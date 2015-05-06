# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:45 markd Exp $

DISTNAME=	collection-omega
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	30388

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Omega packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-aleph-[0-9]*:../../print/tex-aleph
# depend antomega
DEPENDS+=	tex-lambda-[0-9]*:../../print/tex-lambda
# depend mxedruli
DEPENDS+=	tex-omega-[0-9]*:../../print/tex-omega
# depend omegaware
DEPENDS+=	tex-otibet-[0-9]*:../../print/tex-otibet

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
