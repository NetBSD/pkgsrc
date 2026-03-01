# $NetBSD: Makefile,v 1.7 2026/03/01 12:38:26 gdt Exp $

GITHUB_PROJECT=	mmap
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	ocaml-${GITHUB_PROJECT}-1.2.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/mmap/
COMMENT=	File mapping for Ocaml
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-bigarray-compat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
