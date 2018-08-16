# $NetBSD: Makefile,v 1.24 2018/08/16 18:55:03 adam Exp $

VERSION=	2.0.0_rc3
GITHUB_PROJECT=	opam
GITHUB_TAG=	${VERSION:S/_/-/}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://opam.ocaml.org/
COMMENT=	OCaml package manager
LICENSE=	gnu-lgpl-v3
MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=		yes
OCAML_USE_JBUILDER=	yes
OCAML_USE_OPAM=		no # obviously

OCAML_FINDLIB_DIRS+=	opam-installer

do-install:
	for i in opam-installer opam; do \
	cd ${WRKSRC} && _build/install/default/bin/opam-installer -i --prefix \
			${DESTDIR}${PREFIX} \
			--libdir ${OCAML_SITELIBDIR} \
			--docdir ${DESTDIR}/${OCAML_TOPKG_DOCDIR} \
			$$i; \
	done

.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-extlib/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../misc/dose3/buildlink3.mk" # with ocamlgraph option
.include "../../misc/ocaml-cudf/buildlink3.mk"
.include "../../misc/ocaml-opam-file-format/buildlink3.mk"
.include "../../textproc/ocaml-jsonm/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
