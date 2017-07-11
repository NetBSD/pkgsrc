# $NetBSD: Makefile,v 1.29 2017/07/11 11:06:54 jaapb Exp $
#

DISTNAME=	lwt-2.7.1
PKGNAME=	ocaml-${DISTNAME}
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

OCAML_USE_OASIS_DYNRUN=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}" \
			--bindir "${DESTDIR}${PREFIX}/bin" \
			--enable-react --disable-glib

SUBST_CLASSES+=		libev destdir
SUBST_STAGE.libev=	post-configure
SUBST_MESSAGE.libev=	Correcting compiler flags for libev
SUBST_FILES.libev=	setup.data
SUBST_SED.libev=	-e 's%"-lev"%"-lev -L${PREFIX}/lib/ev ${COMPILER_RPATH_FLAG}${PREFIX}/lib/ev"%'

.include "options.mk"
.include "../../mk/ocaml.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
