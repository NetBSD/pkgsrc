# $NetBSD: Makefile,v 1.8 2016/12/30 11:16:58 jaapb Exp $

VERSION=	1.7.0
GITHUB_PROJECT=	ocaml-extlib
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ygrek/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ocaml-extlib/
COMMENT=	Alternative standard library for OCaml
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

BUILD_TARGET=	build

.include "../../devel/ocaml-cppo/buildlink3.mk"
#.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
