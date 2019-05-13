# $NetBSD: Makefile,v 1.1 2019/05/13 10:54:47 jaapb Exp $

GITHUB_PROJECT=	mmap
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	ocaml-${GITHUB_PROJECT}-1.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/mmap/
COMMENT=	File mapping for Ocaml
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
