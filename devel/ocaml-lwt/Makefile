# $NetBSD: Makefile,v 1.16 2015/01/20 14:24:35 jaapb Exp $
#

DISTNAME=	2.4.5
PKGNAME=	ocaml-lwt-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://github.com/ocsigen/lwt/archive/
DIST_SUBDIR=	ocaml-lwt

WRKSRC=	${WRKDIR}/lwt-${DISTNAME}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Cooperative threading library for OCaml
LICENSE=	gnu-lgpl-v2.1

DEPENDS=	ocaml-react-[0-9]*:../../devel/ocaml-react

OCAML_USE_OASIS=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}" --enable-react --disable-text --disable-glib --disable-toplevel

SUBST_CLASSES+=		libev destdir
SUBST_STAGE.libev=	post-configure
SUBST_MESSAGE.libev=	Correcting compiler flags for libev
SUBST_FILES.libev=	setup.data
SUBST_SED.libev=	-e 's%"-lev"%"-lev -L${PREFIX}/lib/ev ${COMPILER_RPATH_FLAG}${PREFIX}/lib/ev"%'
#SUBST_STAGE.destdir=    post-configure
#SUBST_MESSAGE.destdir=  Changing install location to DESTDIR
#SUBST_FILES.destdir=    setup.ml
#SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

.include "options.mk"
.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
