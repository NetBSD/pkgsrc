# $NetBSD: Makefile,v 1.1 2016/05/05 10:28:21 jaapb Exp $

DISTNAME=	ocamlbuild-0.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=ocaml/ocamlbuild/}
COMMENT=	Build system for OCaml
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	ocaml<=4.02.3

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
