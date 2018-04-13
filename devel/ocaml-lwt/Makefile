# $NetBSD: Makefile,v 1.36 2018/04/13 12:52:00 jaapb Exp $
#

.include "Makefile.common"

PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Cooperative threading library for OCaml

#MAKE_JOBS_SAFE=	no
JBUILDER_BUILD_PACKAGES=	lwt

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-use-libev false

OCAML_USE_JBUILDER=	yes

do-configure:
	cd ${WRKSRC} && ocaml src/util/configure.ml ${CONFIGURE_ARGS}

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools_versioned/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
