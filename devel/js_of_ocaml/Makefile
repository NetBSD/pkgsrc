# $NetBSD: Makefile,v 1.8 2015/01/20 16:09:15 jaapb Exp $
#

DISTNAME=	2.5
PKGNAME=	js_of_ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocsigen/js_of_ocaml/archive/
DIST_SUBDIR=	js_of_ocaml

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
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-optcomp/buildlink3.mk"
BUILDLINK_API_DEPENDS.ocaml-optcomp+=   ocaml-optcomp>=1.6
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
