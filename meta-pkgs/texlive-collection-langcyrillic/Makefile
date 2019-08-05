# $NetBSD: Makefile,v 1.11 2019/08/05 09:30:24 markd Exp $

DISTNAME=	collection-langcyrillic
PKGNAME=	texlive-${DISTNAME}-2019pre2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	44895

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Cyrillic TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

# depend babel-belarusian
DEPENDS+=	tex-babel-bulgarian-[0-9]*:../../print/tex-babel-bulgarian
DEPENDS+=	tex-babel-russian-[0-9]*:../../print/tex-babel-russian
# depend babel-serbian
DEPENDS+=	tex-babel-serbianc-[0-9]*:../../print/tex-babel-serbianc
# depend babel-ukrainian
# depend churchslavonic
DEPENDS+=	tex-cmcyr-[0-9]*:../../fonts/tex-cmcyr
DEPENDS+=	tex-cyrillic-[0-9]*:../../print/tex-cyrillic
DEPENDS+=	tex-cyrillic-bin-[0-9]*:../../print/tex-cyrillic-bin
DEPENDS+=	tex-cyrplain-[0-9]*:../../print/tex-cyrplain
# depend disser
# depend eskd
# depend eskdx
# depend gost
DEPENDS+=	tex-hyphen-belarusian-[0-9]*:../../print/tex-hyphen-belarusian
DEPENDS+=	tex-hyphen-bulgarian-[0-9]*:../../print/tex-hyphen-bulgarian
DEPENDS+=	tex-hyphen-churchslavonic-[0-9]*:../../print/tex-hyphen-churchslavonic
DEPENDS+=	tex-hyphen-mongolian-[0-9]*:../../print/tex-hyphen-mongolian
DEPENDS+=	tex-hyphen-russian-[0-9]*:../../print/tex-hyphen-russian
DEPENDS+=	tex-hyphen-serbian-[0-9]*:../../print/tex-hyphen-serbian
DEPENDS+=	tex-hyphen-ukrainian-[0-9]*:../../print/tex-hyphen-ukrainian
DEPENDS+=	tex-lcyw-[0-9]*:../../fonts/tex-lcyw
DEPENDS+=	tex-lh-[0-9]*:../../fonts/tex-lh
# depend lhcyr
# lshort-bulgarian is documentation only
# lshort-mongol is documentation only
# lshort-russian is documentation only
# lshort-ukr is documentation only
# depend mongolian-babel
# depend montex
# mpman-ru is documentation only
# depend numnameru
# pst-eucl-translation-bg is documentation only
DEPENDS+=	tex-ruhyphen-[0-9]*:../../print/tex-ruhyphen
# depend russ
# depend serbian-apostrophe
# depend serbian-date-lat
# depend serbian-def-cyr
# depend serbian-lig
DEPENDS+=	tex-t2-[0-9]*:../../print/tex-t2
# texlive-ru is documentation only
# texlive-sr is documentation only
DEPENDS+=	tex-ukrhyph-[0-9]*:../../print/tex-ukrhyph

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
