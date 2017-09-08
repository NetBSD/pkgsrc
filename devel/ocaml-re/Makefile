# $NetBSD: Makefile,v 1.11 2017/09/08 09:51:22 jaapb Exp $

VERSION=	1.7.1
GITHUB_PROJECT=	ocaml-re
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/ocaml-re/
COMMENT=	Pure OCaml regular expression library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake
OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
