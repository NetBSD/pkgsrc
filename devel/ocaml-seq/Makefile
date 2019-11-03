# $NetBSD: Makefile,v 1.2 2019/11/03 10:39:26 rillig Exp $

GITHUB_PROJECT=	seq
DISTNAME=	${GITHUB_PROJECT}-0.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=c-cube/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/c-cube/seq/
COMMENT=	Ocaml seq library compatibility package
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		# none
USE_TOOLS+=		gmake
OCAML_USE_FINDLIB=	yes

BUILD_TARGET=	build

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
MAKE_ENV+=	OPT=true
.else
MAKE_ENV+=	OPT=false
.endif

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
