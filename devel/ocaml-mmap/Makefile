# $NetBSD: Makefile,v 1.2 2021/03/08 08:12:54 jaapb Exp $

GITHUB_PROJECT=	mmap
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	ocaml-${GITHUB_PROJECT}-1.1.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/mmap/
COMMENT=	File mapping for Ocaml
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
