# $NetBSD: Makefile,v 1.4 2021/03/08 08:12:50 jaapb Exp $

GITHUB_PROJECT=	core
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.13.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/core/
COMMENT=	Standard library overlay for OCaml by Jane Street
LICENSE=	mit

USE_TOOLS+=	bash

OCAML_USE_DUNE=	yes
OCAML_USE_OPAM=	no

SUBST_CLASSES+=			fix-dune-flags
SUBST_STAGE.fix-dune-flags=	post-extract
SUBST_MESSAGE.fix-dune-flags=	Fixing unknown dune flags.
SUBST_FILES.fix-dune-flags=	\
	bench/bin/dune daemon/src/dune daemon/test-bin/dune \
	error_checking_mutex/src/dune \
	example/command/dune lock_file_blocking/src/dune \
	lock_file_blocking/test/dune lock_file_blocking/test-bin/dune \
	nano_mutex/bench/dune src/dune test/bin/manual/dune \
	test/bin/dune test/src/dune time_stamp_counter/bench/dune \
	time_stamp_counter/src/dune
SUBST_SED.fix-dune-flags=	-e 's|-allow-unannotated-ignores||g'
SUBST_SED.fix-dune-flags+=	-e 's|-check-doc-comments||g'

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
    ${OPAM_INSTALL_DIR}/$$i.install; \
  done

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-core_kernel/buildlink3.mk"
.include "../../devel/ocaml-jst-config/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../devel/ocaml-spawn/buildlink3.mk"
.include "../../misc/ocaml-opaline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
