# $NetBSD: Makefile,v 1.7 2022/03/21 07:59:31 jaapb Exp $

DISTNAME=	digestif-1.1.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	digestif
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/digestif/
COMMENT=	Simple hash algorithms in OCaml
LICENSE=	mit

DEPENDS+=	ocaml-bigarray-compat-[0-9]*:../../devel/ocaml-bigarray-compat
DEPENDS+=	ocaml-stdlib-shims-[0-9]*:../../devel/ocaml-stdlib-shims

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake pkg-config
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-eqaf/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
