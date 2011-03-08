# $NetBSD: Makefile,v 1.2 2011/03/08 19:27:27 minskim Exp $

DISTNAME=	collection-fontsrecommended-doc
PKGNAME=	tex-${DISTNAME}-2010
CATEGORIES=	fonts
MASTER_SITES=	# empty
TEXLIVE_REV=	19478

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Documentation for tex-collection-fontsrecommended

# tex-avantgar doesn't have a documentation package.
# tex-bookman doesn't have a documentation package.
DEPENDS+=	tex-charter-doc-[0-9]*:../../fonts/tex-charter-doc
DEPENDS+=	tex-cm-super-doc-[0-9]*:../../fonts/tex-cm-super-doc
# tex-cmextra doesn't have a documentation package.
DEPENDS+=	tex-collection-basic-doc>=2010:../../print/tex-collection-basic-doc
# tex-courier doesn't have a documentation package.
DEPENDS+=	tex-euro-doc-[0-9]*:../../finance/tex-euro-doc
DEPENDS+=	tex-euro-ce-doc-[0-9]*:../../fonts/tex-euro-ce-doc
DEPENDS+=	tex-eurofont-doc-[0-9]*:../../fonts/tex-eurofont-doc
DEPENDS+=	tex-eurosans-doc-[0-9]*:../../fonts/tex-eurosans-doc
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
