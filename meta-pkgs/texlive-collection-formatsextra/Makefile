# $NetBSD: Makefile,v 1.12 2024/03/21 20:00:52 markd Exp $

DISTNAME=	collection-formatsextra
PKGNAME=	texlive-${DISTNAME}-2024
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	62226

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Additional formats for TeX

DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-aleph-[0-9]*:../../print/tex-aleph
DEPENDS+=	tex-antomega-[0-9]*:../../print/tex-antomega
DEPENDS+=	tex-edmac-[0-9]*:../../print/tex-edmac
DEPENDS+=	tex-eplain-[0-9]*:../../print/tex-eplain
DEPENDS+=	tex-hitex-[0-9]*:../../print/tex-hitex
DEPENDS+=	tex-jadetex-[0-9]*:../../print/tex-jadetex
DEPENDS+=	tex-lambda-[0-9]*:../../print/tex-lambda
DEPENDS+=	tex-lollipop-[0-9]*:../../print/tex-lollipop
DEPENDS+=	tex-mltex-[0-9]*:../../print/tex-mltex
DEPENDS+=	tex-mxedruli-[0-9]*:../../fonts/tex-mxedruli
DEPENDS+=	tex-omega-[0-9]*:../../print/tex-omega
# omegaware is entirely included in web2c
DEPENDS+=	tex-otibet-[0-9]*:../../print/tex-otibet
DEPENDS+=	tex-passivetex-[0-9]*:../../print/tex-passivetex
DEPENDS+=	tex-psizzl-[0-9]*:../../print/tex-psizzl
DEPENDS+=	tex-startex-[0-9]*:../../print/tex-startex
DEPENDS+=	tex-texsis-[0-9]*:../../print/tex-texsis
DEPENDS+=	tex-xmltex-[0-9]*:../../textproc/tex-xmltex
DEPENDS+=	tex-xmltexconfig-[0-9]*:../../textproc/tex-xmltexconfig

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
