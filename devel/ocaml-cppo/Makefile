# $NetBSD: Makefile,v 1.15 2018/01/23 09:54:04 wiz Exp $

DISTNAME=	cppo-1.6.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	cppo

MAINTAINER=	jaapb@NetBSD.org
#HOMEPAGE=	http://mjambon.com/cppo.html
COMMENT=	C-style preprocessor for OCaml
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

OCAML_USE_JBUILDER=	yes
OCAML_USE_OPAM=		no # opam depends on this

INSTALLATION_DIRS+=	bin ${OCAML_SITELIBDIR}/cppo_ocamlbuild \
			share/doc/ocaml-cppo share/doc/ocaml-cppo_ocamlbuild
OCAML_FINDLIB_DIRS+=    cppo_ocamlbuild

.include "../../mk/ocaml.mk"

# Normally, we'd do this using opam-installer, but that requires
# this package.
do-install:
	for i in LICENSE.md README.md; do \
		${INSTALL_DATA} ${WRKSRC}/_build/install/default/doc/cppo/$$i \
		${DESTDIR}${PREFIX}/share/doc/ocaml-cppo; \
		${INSTALL_DATA} ${WRKSRC}/_build/install/default/doc/cppo_ocamlbuild/$$i \
		${DESTDIR}${PREFIX}/share/doc/ocaml-cppo_ocamlbuild; \
	done
	for i in META opam; do \
		${INSTALL_DATA} ${WRKSRC}/_build/install/default/lib/cppo/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cppo; \
	done
	for i in META opam ocamlbuild_cppo.cmi ocamlbuild_cppo.cmt \
		ocamlbuild_cppo.cmti ocamlbuild_cppo.mli \
		cppo_ocamlbuild.cma; do \
		${INSTALL_DATA} ${WRKSRC}/_build/install/default/lib/cppo_ocamlbuild/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cppo_ocamlbuild; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/_build/install/default/bin/cppo \
		${DESTDIR}${PREFIX}/bin
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	for i in ocamlbuild_cppo.cmx cppo_ocamlbuild.cmxa cppo_ocamlbuild.a \
		cppo_ocamlbuild.cmxs; do \
		${INSTALL_DATA} ${WRKSRC}/_build/install/default/lib/cppo_ocamlbuild/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cppo_ocamlbuild; \
	done
.endif

.include "../../devel/ocamlbuild/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocamlbuild?=        full
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
