# $NetBSD: Makefile,v 1.34 2011/01/13 13:39:10 wiz Exp $

DISTNAME=		advi-1.6.0
PKGREVISION=		9
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/Projects/cristal/advi/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cristal.inria.fr/advi/
COMMENT=		Active-DVI Presenter

BUILD_DEPENDS+=		ocaml>=3.04:../../lang/ocaml

TEX_ACCEPTED=		teTeX3
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gs:run
CONFIGURE_ARGS+=	--libdir=${PKG_LOCALTEXMFPREFIX:Q}

# subst.mk ignores the files it thinks are not text files
_SUBST_IS_TEXT_FILE=	true

SUBST_CLASSES+=		gspath
SUBST_MESSAGE.gspath=	Fixing gs pathname in binary.
SUBST_STAGE.gspath=	pre-configure
SUBST_FILES.gspath=	config.ml.in
SUBST_SED.gspath=	-e "s,@PATH_GS@,${PREFIX}/bin/gs,g"

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing config file path.
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	userfile.ml
SUBST_SED.paths=	-e "s:/etc/advirc:${PKG_SYSCONFDIR}/advirc:g"

.include "../../print/teTeX/module.mk"

post-extract:
	${CP} ${WRKSRC}/tex/*.eps ${WRKSRC}/doc
	${CP} ${WRKSRC}/doc/eng.htm ${WRKSRC}/doc/index.html
	${MKDIR} ${WRKSRC}/doc.orig
	${CP} ${WRKSRC}/doc/*.dvi ${WRKSRC}/doc.orig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/advi
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.ps *.pdf \
		${PREFIX}/share/doc/advi
	cd ${WRKSRC}/doc.orig && ${INSTALL_DATA} *.dvi \
		${PREFIX}/share/doc/advi
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/advi
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.css *.jpg *.gif \
		${PREFIX}/share/doc/html/advi
	cd ${PREFIX}/share/doc/html/advi && ${LN} -sf ../../advi/manual.* .

.include "../../lang/ocaml/buildlink3.mk"
.include "../../graphics/camlimages/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/lablgtk1/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/ocaml-graphics/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
