# $NetBSD: Makefile,v 1.75 2014/05/05 00:48:16 ryoon Exp $

DISTNAME=		advi-1.10.1
PKGREVISION=		34
CATEGORIES=		print
MASTER_SITES=		http://gallium.inria.fr/advi/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gallium.inria.fr/advi/
COMMENT=		Active-DVI Presenter
LICENSE=		gnu-lgpl-v2

BUILD_DEPENDS+=		ocaml>=3.04:../../lang/ocaml
BUILD_DEPENDS+=		ocaml-findlib>=1.2.6:../../devel/ocaml-findlib
DEPENDS+=		camlimages>=4.0.0:../../graphics/camlimages

# "Scripts installed by texlive-tetex have been moved to tex-fontinst,
# tex-pstools, and tex-cyrillic-bin in TeX Live 2013."
#DEPENDS+=		texlive-tetex>=2010:../../print/texlive-tetex
DEPENDS+=		tex-fontinst>=1.933:../../fonts/tex-fontinst
DEPENDS+=		tex-pstools>=1.68:../../graphics/tex-pstools
DEPENDS+=		tex-cyrillic-bin>=2013:../../print/tex-cyrillic-bin

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gs:run
GNU_CONFIGURE_LIBDIR=	${PREFIX}/share/texmf-dist
CONFIGURE_ARGS+=	--with-gs=${PREFIX}/bin/gs

INSTALL_UNSTRIPPED=	yes

SUBST_CLASSES+=		gs
SUBST_STAGE.gs=		post-configure
SUBST_FILES.gs=		src/config.ml.in
SUBST_SED.gs=		-e 's,@GS@,gs,'
SUBST_MESSAGE.gs=	Fixing hard-coded path to gs

INSTALLATION_DIRS=	share/doc/advi share/doc/html/advi

post-extract:
	${CP} ${WRKSRC}/tex/*.eps ${WRKSRC}/doc
	${MKDIR} ${WRKSRC}/doc.orig
	${CP} ${WRKSRC}/doc/*.dvi ${WRKSRC}/doc.orig

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.ps *.pdf \
		${DESTDIR}${PREFIX}/share/doc/advi
	cd ${WRKSRC}/doc.orig && ${INSTALL_DATA} *.dvi \
		${DESTDIR}${PREFIX}/share/doc/advi
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.gif \
		${DESTDIR}${PREFIX}/share/doc/html/advi
	cd ${DESTDIR}${PREFIX}/share/doc/html/advi && ${LN} -sf ../../advi/manual.* .

.include "../../print/kpathsea/texmf.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../graphics/camlimages/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/ocaml-graphics/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
