# $NetBSD: Makefile,v 1.3 2017/09/06 12:21:29 markd Exp $

DISTNAME=	collection-fontsrecommended-doc
PKGNAME=	texlive-${DISTNAME}-2010
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	19478

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Documentation for texlive-collection-fontsrecommended

DEPENDS+=	texlive-collection-basic-doc>=2010:../../meta-pkgs/texlive-collection-basic-doc

# tex-avantgar doesn't have a documentation package.
# tex-bookman doesn't have a documentation package.
DEPENDS+=	tex-charter-doc-[0-9]*:../../fonts/tex-charter-doc
DEPENDS+=	tex-cm-super-doc-[0-9]*:../../fonts/tex-cm-super-doc
# tex-cmextra doesn't have a documentation package.
# tex-courier doesn't have a documentation package.
DEPENDS+=	tex-euro-doc-[0-9]*:../../finance/tex-euro-doc
DEPENDS+=	tex-euro-ce-doc-[0-9]*:../../fonts/tex-euro-ce-doc
DEPENDS+=	tex-eurosym-doc-[0-9]*:../../fonts/tex-eurosym-doc
DEPENDS+=	tex-fpl-doc-[0-9]*:../../fonts/tex-fpl-doc
# tex-helvetic doesn't have a documentation package.
DEPENDS+=	tex-lm-doc-[0-9]*:../../fonts/tex-lm-doc
DEPENDS+=	tex-marvosym-doc-[0-9]*:../../fonts/tex-marvosym-doc
DEPENDS+=	tex-mathpazo-doc-[0-9]*:../../fonts/tex-mathpazo-doc
# tex-ncntrsbk doesn't have a documentation package.
# tex-palatino doesn't have a documentation package.
DEPENDS+=	tex-pxfonts-doc-[0-9]*:../../fonts/tex-pxfonts-doc
DEPENDS+=	tex-rsfs-doc-[0-9]*:../../fonts/tex-rsfs-doc
# tex-symbol doesn't have a documentation package.
DEPENDS+=	tex-tex-gyre-doc-[0-9]*:../../fonts/tex-tex-gyre-doc
# tex-tims doesn't have a documentation package.
DEPENDS+=	tex-tipa-doc-[0-9]*:../../fonts/tex-tipa-doc
DEPENDS+=	tex-txfonts-doc-[0-9]*:../../fonts/tex-txfonts-doc
DEPENDS+=	tex-utopia-doc-[0-9]*:../../fonts/tex-utopia-doc
DEPENDS+=	tex-wasy-doc-[0-9]*:../../fonts/tex-wasy-doc
DEPENDS+=	tex-wasysym-doc-[0-9]*:../../fonts/tex-wasysym-doc
# tex-zapfchan doesn't have a documentation package.
# tex-zapfding doesn't have a documentation package.

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
