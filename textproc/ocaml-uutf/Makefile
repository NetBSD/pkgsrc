# $NetBSD: Makefile,v 1.16 2018/11/12 16:10:28 jaapb Exp $

DISTNAME=	uutf-1.0.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://erratique.ch/software/uutf/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/uutf/
COMMENT=	Unicode library for OCaml
LICENSE=	isc

OCAML_USE_TOPKG=	yes
INSTALLATION_DIRS+=	bin share/doc/uutf

.include "../../mk/ocaml.mk"

# Normally, we'd do this using opam-installer, but that requires
# this package.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/test/utftrip.native \
		${DESTDIR}${PREFIX}/bin/utftrip
	for i in CHANGES.md LICENSE.md README.md; do \
		${INSTALL_DATA} ${WRKSRC}/_build/$$i \
		${DESTDIR}${PREFIX}/share/doc/uutf; \
	done
	${INSTALL_DATA} ${WRKSRC}/_build/opam \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/uutf/opam
	for i in pkg/META src/uutf.cma src/uutf.cmi src/uutf.cmti \
		src/uutf.mli; do \
		${INSTALL_DATA} ${WRKSRC}/_build/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/uutf; \
	done
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	for i in uutf.a uutf.cmx uutf.cmxa uutf.cmxs; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/uutf; \
	done
.endif

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../textproc/ocaml-uchar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
