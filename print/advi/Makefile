# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:03 tv Exp $

DISTNAME=		advi-1.4.0
PKGREVISION=		4
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/Projects/cristal/advi/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pauillac.inria.fr/advi/
COMMENT=		Active-DVI Presenter

DEPENDS+=		teTeX-[0-9]*:../../print/teTeX

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

post-extract:
	@${CP} ${WRKSRC}/tex/*.eps ${WRKSRC}/doc

post-configure:
	@for f in ${WRKSRC}/userfile.ml; do				\
		${SED} -e 's:/etc/advirc:${PKG_SYSCONFDIR}/advirc:g'	\
		$$f >> $$f.tmp && ${MV} $$f.tmp $$f;			\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/advi
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.dvi *.ps *.pdf \
		${PREFIX}/share/doc/advi
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/advi
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.css *.jpg *.gif \
		${PREFIX}/share/doc/html/advi
	cd ${PREFIX}/share/doc/html/advi && ${LN} -sf ../../advi/manual.* .
	${INSTALL_MAN} ${WRKSRC}/doc/advi.1 ${PREFIX}/man/man1

.include "../../lang/ocaml/buildlink3.mk"
.include "../../graphics/camlimages/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
