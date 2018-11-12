# $NetBSD: Makefile,v 1.6 2018/11/12 16:10:25 jaapb Exp $

DISTNAME=	topkg-0.9.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://erratique.ch/software/topkg/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/topkg/
COMMENT=	Transitory OCaml software packager
LICENSE=	isc

OCAML_USE_TOPKG=	yes
INSTALLATION_DIRS+=	share/doc/topkg

.include "../../mk/ocaml.mk"

# Normally, we'd do this using opam-installer, but that requires
# devel/ocaml-cmdliner, which requires this package.
do-install:
	for i in CHANGES.md LICENSE.md README.md; do \
		${INSTALL_DATA} ${WRKSRC}/_build/$$i \
		${DESTDIR}${PREFIX}/share/doc/topkg; \
	done
	${INSTALL_DATA} ${WRKSRC}/_build/topkg.opam \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/topkg/opam
	for i in pkg/META src/topkg.cma src/topkg.cmi src/topkg.cmti \
		src/topkg.mli; do \
		${INSTALL_DATA} ${WRKSRC}/_build/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/topkg; \
	done
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	for i in topkg.a topkg.cmx topkg.cmxa topkg.cmxs topkg_build.cmx \
		topkg_cmd.cmx topkg_codec.cmx topkg_conf.cmx topkg_distrib.cmx \
		topkg_fexts.cmx topkg_fpath.cmx topkg_install.cmx \
		topkg_ipc.cmx topkg_log.cmx topkg_main.cmx topkg_opam.cmx \
		topkg_os.cmx topkg_pkg.cmx topkg_publish.cmx topkg_result.cmx \
		topkg_string.cmx topkg_test.cmx topkg_vcs.cmx; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/topkg; \
	done
.endif

.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
