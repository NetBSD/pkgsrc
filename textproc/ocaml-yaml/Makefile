# $NetBSD: Makefile,v 1.1 2026/10/24 18:08:25 alnsn Exp $

DISTNAME=	yaml-3.2.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=avsm/}
GITHUB_PROJECT=	ocaml-yaml
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/avsm/ocaml-yaml/
COMMENT=	OCaml interface to the YAML 1.1 spec
LICENSE=	isc

USE_LANGUAGE=		c
OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	yaml

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-ctypes/buildlink3.mk"
.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../devel/ocaml-bos/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
