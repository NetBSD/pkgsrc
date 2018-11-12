# $NetBSD: Makefile,v 1.111 2018/11/12 16:10:23 jaapb Exp $

VERSION=		4.0.1
PKGNAME=		camlimages-${VERSION}
PKGREVISION=		73
CATEGORIES=		graphics
MASTER_SITES=		https://bitbucket.org/camlspotter/camlimages/get/
DISTNAME=		v${VERSION}
DIST_SUBDIR=		${PKGNAME_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gallium.inria.fr/camlimages/
COMMENT=		Image processing library for Objective Caml
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		omake>=0.9.8.6.0rc1:../../devel/omake
BUILD_DEPENDS+=		ocaml-findlib>=1.2.6:../../devel/ocaml-findlib

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/camlspotter-camlimages-v${VERSION}

SUBST_CLASSES+=		omf
SUBST_STAGE.omf=	pre-configure
SUBST_FILES.omf=	OMakefile
SUBST_SED.omf=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.omf+=		-e 's,@X11BASE@,${X11BASE},g'
SUBST_SED.omf+=		-e s%@LDFLAGS@%${LDFLAGS:Q}%g
SUBST_SED.omf+=		-e 's,@OCAMLFIND_DESTDIR@,${DESTDIR}${PREFIX}/lib/ocaml/site-lib,g'
SUBST_SED.omf+=		-e 's,@OCAMLFIND_LDCONF@,/dev/null,g'
SUBST_MESSAGE.omf=	Fixing vars in OMakefile

INSTALLATION_DIRS=	lib/ocaml/site-lib

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/omake --configure --verbose

do-install:
	cd ${WRKSRC} && OCAMLFIND_DESTDIR=${DESTDIR}${PREFIX}/lib/ocaml/site-lib \
		OCAMLFIND_LDCONF=/dev/null ${PREFIX}/bin/omake install

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.11.0
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../x11/ocaml-graphics/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
