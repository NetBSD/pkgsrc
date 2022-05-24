# $NetBSD: Makefile,v 1.3 2022/05/24 18:51:56 jaapb Exp $

GITHUB_PROJECT=	xml-light
DISTNAME=	${GITHUB_PROJECT}-2.4
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ncannasse/}
DIST_SUBDIR=	ocaml-${GITHUB_PROJECT}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ncannasse/xml-light/
COMMENT=	Minimal Xml parser and printer
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

OCAML_USE_FINDLIB=	yes

.include "../../lang/ocaml/ocaml.mk"

BUILD_TARGET=	all
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	opt
MAKE_ENV+=	NATDYNLINK=YES
.else
MAKE_ENV+=	NATDYNLINK=NO
.endif
INSTALL_TARGET=	install_ocamlfind

.include "../../mk/bsd.pkg.mk"
