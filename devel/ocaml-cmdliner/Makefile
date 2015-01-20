# $NetBSD: Makefile,v 1.3 2015/01/20 14:24:35 jaapb Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	cmdliner-0.9.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/cmdliner/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/cmdliner/
COMMENT=	Module for the declarative definition of command line interfaces
LICENSE=	modified-bsd

USE_LANGUAGES=	c
OCAML_SITELIBDIR=	${PREFIX}/lib/ocaml/site-lib
INSTALLATION_DIRS=	lib/ocaml/site-lib/cmdliner

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
OPTARG=	true
PLIST.opt=	yes
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./pkg/build ${OPTARG}

do-install:
	for i in `cat ${WRKSRC}/cmdliner.program`; do \
	${INSTALL_PROGRAM} ${WRKSRC}/_build/$$i ${DESTDIR}${OCAML_SITELIBDIR}/cmdliner; \
	done
	for i in `cat ${WRKSRC}/cmdliner.lib`; do \
	${INSTALL_LIB} ${WRKSRC}/_build/$$i ${DESTDIR}${OCAML_SITELIBDIR}/cmdliner; \
	done
	for i in `cat ${WRKSRC}/cmdliner.data`; do \
	${INSTALL_DATA} ${WRKSRC}/_build/$$i ${DESTDIR}${OCAML_SITELIBDIR}/cmdliner; \
	done

post-install:
	for i in META cmdliner.a cmdliner.cma cmdliner.cmi cmdliner.cmx cmdliner.cmxa cmdliner.mli; do \
		${CHMOD} -x ${DESTDIR}${OCAML_SITELIBDIR}/cmdliner/$$i; \
	done

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
