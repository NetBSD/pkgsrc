# $NetBSD: Makefile,v 1.22 2016/02/23 15:03:16 joerg Exp $
#

DISTNAME=	lwt-2.5.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	http://github.com/ocsigen/lwt/archive/
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}
GITHUB_PROJECT=	lwt

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Cooperative threading library for OCaml
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	ocaml-ppx_tools-[0-9]*:../../devel/ocaml-ppx_tools
DEPENDS+=	ocaml-react-[0-9]*:../../devel/ocaml-react
BUILDLINK_API_DEPENDS.ocaml-ssl+=	ocaml-ssl>=0.5.0

OCAML_USE_OASIS=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}" --enable-react \
	--disable-glib

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
.include "../../mk/bsd.pkg.mk"
