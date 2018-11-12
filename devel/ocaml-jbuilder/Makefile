# $NetBSD: Makefile,v 1.10 2018/11/12 16:10:19 jaapb Exp $

GITHUB_PROJECT=	jbuilder
GITHUB_TAG=	${PKGVERSION_NOREV:S/_/+/}
DISTNAME=	${GITHUB_PROJECT}-1.0_beta20
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/jbuilder/
COMMENT=	Composable build system for OCaml
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/dune-${PKGVERSION_NOREV:S/_/-/}
USE_LANGUAGES=	# none
UNLIMIT_RESOURCES+=	stacksize

BUILD_TARGET=	default
MAKE_ENV+=	MAKE_JOBS=${MAKE_JOBS:U1}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${OCAML_SITELIBDIR}/jbuilder

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	jbuilder stublibs

.include "../../mk/ocaml.mk"

# Installation via OPAM does not work (OPAM needs to be set up)
do-install:
	for i in META; do \
		${INSTALL_DATA} ${WRKSRC}/_build/install/default/lib/jbuilder/$$i \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/jbuilder; \
	done;
	for i in jbuilder; do \
		${INSTALL_PROGRAM} ${WRKSRC}/_build/install/default/bin/$$i \
		${DESTDIR}${PREFIX}/bin; \
	done;
	for i in jbuilder.1 jbuilder-build.1 jbuilder-clean.1 \
		jbuilder-exec.1 jbuilder-external-lib-deps.1 \
		jbuilder-install.1 jbuilder-installed-libraries.1 jbuilder-rules.1 \
		jbuilder-runtest.1 jbuilder-subst.1 jbuilder-uninstall.1; do \
		${INSTALL_MAN} ${WRKSRC}/_build/install/default/man/man1/$$i \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done;

.include "../../mk/bsd.pkg.mk"
