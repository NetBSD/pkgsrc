# $NetBSD: Makefile,v 1.10 2005/02/04 21:50:25 adrianp Exp $

DISTNAME=		advi-1.6.0
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/Projects/cristal/advi/
EXTRACT_SUFX=           .tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pauillac.inria.fr/advi/
COMMENT=		Active-DVI Presenter

DEPENDS+=		teTeX-[0-9]*:../../print/teTeX
BUILD_DEPENDS+=		ocaml>=3.04:../../lang/ocaml

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

post-extract:
	@${CP} ${WRKSRC}/tex/*.eps ${WRKSRC}/doc
	@${CP} ${WRKSRC}/doc/eng.htm ${WRKSRC}/doc/index.html
	@${MKDIR} ${WRKSRC}/doc.orig
	@${CP} ${WRKSRC}/doc/*.dvi ${WRKSRC}/doc.orig

post-configure:
	@for f in ${WRKSRC}/userfile.ml; do				\
		${SED} -e 's:/etc/advirc:${PKG_SYSCONFDIR}/advirc:g'	\
		$$f >> $$f.tmp && ${MV} $$f.tmp $$f;			\
	done

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
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../x11/ocaml-graphics/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
