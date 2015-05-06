# $NetBSD: Makefile,v 1.2 2015/05/06 10:18:59 markd Exp $

DISTNAME=	collection-genericrecommended-doc
PKGNAME=	texlive-${DISTNAME}-2013
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	30396

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Documentation for texlive-collection-genericrecommended

DEPENDS+=	texlive-collection-basic-doc-[0-9]*:../../meta-pkgs/texlive-collection-basic-doc

DEPENDS+=	tex-epsf-doc-[0-9]*:../../print/tex-epsf-doc
DEPENDS+=	tex-fontname-doc-[0-9]*:../../fonts/tex-fontname-doc
# tex-genmisc-doc doeesn't have a documentation package
DEPENDS+=	tex-kastrup-doc-[0-9]*:../../math/tex-kastrup-doc
DEPENDS+=	tex-multido-doc-[0-9]*:../../devel/tex-multido-doc
DEPENDS+=	tex-path-doc-[0-9]*:../../print/tex-path-doc
DEPENDS+=	tex-tex-ps-doc-[0-9]*:../../graphics/tex-tex-ps-doc
DEPENDS+=	tex-ulem-doc-[0-9]*:../../print/tex-ulem-doc

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
