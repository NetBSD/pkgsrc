# $NetBSD: Makefile,v 1.12 2018/11/12 16:10:27 jaapb Exp $

DISTNAME=	jsonm-1.0.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://erratique.ch/software/jsonm/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/jsonm/
COMMENT=	OCaml streaming codec for JSON
LICENSE=	isc

OCAML_USE_TOPKG=	yes
INSTALLATION_DIRS+=	bin share/doc/jsonm

.include "../../mk/ocaml.mk"

# Normally, we'd do this using opam-installer, but that requires
# this package.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/test/jsontrip.native \
		${DESTDIR}${PREFIX}/bin/jsontrip
	for i in CHANGES.md LICENSE.md README.md test/examples.ml test/jtree.ml; do \
		${INSTALL_DATA} ${WRKSRC}/_build/$$i \
		${DESTDIR}${PREFIX}/share/doc/jsonm; \
	done
	${INSTALL_DATA} ${WRKSRC}/_build/opam \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/jsonm/opam
	for i in pkg/META src/jsonm.cma src/jsonm.cmi src/jsonm.cmti \
		src/jsonm.mli; do \
		${INSTALL_DATA} ${WRKSRC}/_build/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/jsonm; \
	done
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	for i in jsonm.a jsonm.cmx jsonm.cmxa jsonm.cmxs; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/jsonm; \
	done
.endif

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
