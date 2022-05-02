# $NetBSD: Makefile,v 1.4 2022/05/02 13:53:44 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.2.2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=c-cube/}
GITHUB_PROJECT=	seq

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/c-cube/seq/
COMMENT=	Ocaml seq library compatibility package
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
