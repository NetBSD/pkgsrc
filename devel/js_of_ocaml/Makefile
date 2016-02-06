# $NetBSD: Makefile,v 1.11 2016/02/06 14:00:13 jaapb Exp $
#

GITHUB_PROJECT=	js_of_ocaml
DISTNAME=	${GITHUB_PROJECT}-2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocsigen.org/js_of_ocaml/
COMMENT=	Compiler of OCaml bytecode to Javascript
LICENSE=	gnu-lgpl-v2

DEPENDS+=	ocaml-deriving-ocsigen>=0.6:../../devel/ocaml-deriving-ocsigen
DEPENDS+=	menhir-[0-9]*:../../devel/menhir

USE_TOOLS=	gmake

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}
MAKE_ENV=	BINDIR=${DESTDIR}/${PREFIX}/bin DESTDIR=${DESTDIR} OCAML_SITELIBDIR=${OCAML_SITELIBDIR}
MAKE_JOBS_SAFE=	no

.include "options.mk"
.include "../../devel/ocaml-base64/buildlink3.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-optcomp/buildlink3.mk"
BUILDLINK_API_DEPENDS.ocaml-optcomp+=   ocaml-optcomp>=1.6
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
