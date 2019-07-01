# $NetBSD: Makefile,v 1.2 2019/07/01 12:38:53 jaapb Exp $

GITHUB_PROJECT=	core
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.12.3
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/core/
COMMENT=	Standard library overlay for OCaml by Jane Street
LICENSE=	mit

USE_TOOLS+=	bash

OCAML_USE_DUNE=	yes
OCAML_USE_OPAM=	no

# needs specific install command because it has shell scripts
do-install:
	${RUN} for i in ${OPAM_INSTALL_FILES}; do \
		cd ${WRKSRC} && opaline -install-cmd "${INSTALL_DATA}" \
		-exec-install-cmd "${INSTALL_DATA}" \
		-name $$i \
		-destdir ${DESTDIR} \
		-prefix ${PREFIX} \
		-libdir ${PREFIX}/${OCAML_SITELIBDIR} \
		-docdir ${OCAML_TOPKG_DOCDIR}/$$i \
		-stublibsdir ${PREFIX}/${OCAML_SITELIBDIR}/stublibs \
		-bindir ${PREFIX}/bin \
    $$i.install; \
  done

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-core_kernel/buildlink3.mk"
.include "../../devel/ocaml-jst-config/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../devel/ocaml-spawn/buildlink3.mk"
.include "../../misc/ocaml-opaline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
