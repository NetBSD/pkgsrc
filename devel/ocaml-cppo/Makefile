# $NetBSD: Makefile,v 1.2 2016/02/07 10:44:47 wiz Exp $

DISTNAME=	cppo-1.3.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}
GITHUB_PROJECT=	cppo
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=mjambon/cppo/}
COMMENT=	C-style preprocessor for OCaml
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/cppo-1.3.1
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

.include "../../mk/bsd.pkg.mk"
