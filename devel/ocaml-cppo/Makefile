# $NetBSD: Makefile,v 1.5 2016/06/17 10:57:47 jaapb Exp $

VERSION=	1.3.2
GITHUB_PROJECT=	cppo
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://mjambom.com/cppo.html
COMMENT=	C-style preprocessor for OCaml
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

BUILD_TARGET=	ocamlbuild all
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	opt
MAKE_ENV+=	BEST=.native NATDYNLINK=YES
.else
MAKE_ENV+=	BEST=.byte
.endif

MAKE_ENV+=	BINDIR=${DESTDIR}/${PREFIX}/bin DESTDIR=${DESTDIR} OCAML_SITELIBDIR=${OCAML_SITELIBDIR}
INSTALLATION_DIRS+=	bin ${OCAML_SITELIBDIR}/cppo_ocamlbuild
OCAML_FINDLIB_DIRS=	cppo_ocamlbuild

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
