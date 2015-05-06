# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:44 markd Exp $

DISTNAME=	collection-mathextra
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	36538

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Mathematics TeX packages

DEPENDS+=	texlive-collection-fontsrecommended-[0-9]*:../../meta-pkgs/texlive-collection-fontsrecommended
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

# depend 12many
# depend amstex
# depend backnaur
# depend begriff
# depend binomexp
# depend boldtensors
# depend bosisio
# depend bropd
# depend calculation
DEPENDS+=	tex-ccfonts-[0-9]*:../../fonts/tex-ccfonts
# depend commath
DEPENDS+=	tex-concmath-[0-9]*:../../fonts/tex-concmath
DEPENDS+=	tex-concrete-[0-9]*:../../fonts/tex-concrete
# depend conteq
# depend ebproof
# depend eqnarray
# depend extarrows
# depend extpfeil
# depend faktor
# depend grundgesetze
# depend interval
# depend ionumbers
# depend isomath
# depend logicproof
# depend lpform
# depend lplfitch
# depend mathcomp
# depend mattens
# depend mhequ
# depend multiobjective
# depend natded
# depend nath
# depend ot-tableau
DEPENDS+=	tex-oubraces-[0-9]*:../../print/tex-oubraces
# depend perfectcut
# depend prftree
# depend proba
# depend rec-thy
# depend ribbonproofs
# depend sesamanuel
# depend shuffle
# depend skmath
DEPENDS+=	tex-statex-[0-9]*:../../print/tex-statex
# depend statex2
DEPENDS+=	tex-stmaryrd-[0-9]*:../../fonts/tex-stmaryrd
# depend subsupscripts
# depend susy
# depend syllogism
# depend sympytexpackage
# depend synproof
# depend tablor
# depend tensor
# depend tex-ewd
# depend thmbox
# depend turnstile
# depend unicode-math
# depend venn
# depend yhmath
# depend ytableau

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
