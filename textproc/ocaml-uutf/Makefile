# $NetBSD: Makefile,v 1.4 2015/01/20 16:04:57 jaapb Exp $

DISTNAME=	uutf-0.9.3
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://erratique.ch/software/uutf/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/uutf/releases/
COMMENT=	Unicode library for OCaml
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/uutf
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

do-build:
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./pkg/build true
.else
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./pkg/build false
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/_build/pkg/META ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/uutf
	for i in uutf.mli uutf.cmi uutf.cma; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/uutf; \
	done
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	for i in uutf.cmx uutf.a uutf.cmxa uutf.cmxs; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/uutf; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
