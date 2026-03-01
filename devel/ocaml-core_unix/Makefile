# $NetBSD: Makefile,v 1.7 2026/03/01 12:38:22 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	core_unix
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/core_unix/
COMMENT=	Standard library overlay for OCaml by Jane Street (unix-specific)
LICENSE=	mit

TOOL_DEPENDS+=	ocaml-opaline-[0-9]*:../../misc/ocaml-opaline

USE_TOOLS+=	bash

OCAML_USE_DUNE=		yes
OCAML_USE_OPAM=		no
OCAML_USE_FINDLIB=	yes

OCAML_FINDLIB_DIRS=	${GITHUB_PROJECT}

# needs specific install command because it has shell scripts
# that it wants to install in bindir
do-install:
	${RUN} for i in ${OPAM_INSTALL_FILES}; do \
		cd ${WRKSRC} && opaline -install-cmd "${INSTALL_DATA}" \
		-exec-install-cmd "${INSTALL_DATA}" \
		-name $$i \
		-destdir "${DESTDIR}" \
		-prefix "${PREFIX}" \
		-libdir "${PREFIX}/${OCAML_SITELIBDIR}" \
		-docdir "${OCAML_TOPKG_DOCDIR}" \
		-stublibsdir "${PREFIX}/${OCAML_SITELIBDIR}/stublibs" \
		-bindir "${PREFIX}/bin" \
		${OPAM_INSTALL_DIR}/$$i.install; \
	done

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-core/buildlink3.mk"
.include "../../devel/ocaml-core_kernel/buildlink3.mk"
.include "../../devel/ocaml-expect_test_helpers_core/buildlink3.mk"
.include "../../devel/ocaml-jane-street-headers/buildlink3.mk"
.include "../../devel/ocaml-jst-config/buildlink3.mk"
.include "../../devel/ocaml-intrinsics/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../devel/ocaml-spawn/buildlink3.mk"
.include "../../time/ocaml-timezone/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
