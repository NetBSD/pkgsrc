# $NetBSD: Makefile,v 1.14 2017/09/08 09:51:20 jaapb Exp $

PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
DISTNAME=	cmdliner-1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/cmdliner/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/cmdliner/
COMMENT=	Module for the declarative definition of command line interfaces
LICENSE=	isc

USE_LANGUAGES=	c

OCAML_USE_TOPKG=	yes
INSTALLATION_DIRS+=	share/doc/cmdliner

.include "../../mk/ocaml.mk"

# Normally, we'd do this using opam-installer, but that requires
# this package.
do-install:
	for i in CHANGES.md LICENSE.md README.md test/chorus.ml test/cp_ex.ml \
		test/darcs_ex.ml test/revolt.ml test/rm_ex.ml test/tail_ex.ml; do \
		${INSTALL_DATA} ${WRKSRC}/_build/$$i \
		${DESTDIR}${PREFIX}/share/doc/cmdliner; \
	done
	${INSTALL_DATA} ${WRKSRC}/_build/opam \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cmdliner/opam
	for i in pkg/META src/cmdliner.cma src/cmdliner.cmi src/cmdliner.cmti \
		src/cmdliner.mli; do \
		${INSTALL_DATA} ${WRKSRC}/_build/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cmdliner; \
	done
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	for i in cmdliner.a cmdliner.cmx cmdliner.cmxa cmdliner.cmxs \
		cmdliner_arg.cmx cmdliner_base.cmx cmdliner_cline.cmx cmdliner_docgen.cmx \
		cmdliner_info.cmx cmdliner_manpage.cmx cmdliner_msg.cmx \
		cmdliner_suggest.cmx cmdliner_term.cmx cmdliner_trie.cmx; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cmdliner; \
	done
.endif

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
