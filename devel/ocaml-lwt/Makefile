# $NetBSD: Makefile,v 1.31 2017/09/08 16:54:31 jaapb Exp $
#

.include "Makefile.common"

PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Cooperative threading library for OCaml

JBUILDER_BUILD_TARGETS=	lwt

CONFIGURE_ARGS=	-use-libev false

do-configure:
	cd ${WRKSRC} && ocaml src/util/configure.ml ${CONFIGURE_ARGS}

.include "options.mk"
.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools_versioned/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
