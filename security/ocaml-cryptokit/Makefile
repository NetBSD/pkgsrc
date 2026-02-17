# $NetBSD: Makefile,v 1.28 2026/02/17 13:39:12 wiz Exp $
#

VERSION=	1.17
GITHUB_PROJECT=	cryptokit
GITHUB_TAG=	release${VERSION:S/.//}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=xavierleroy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xavierleroy/cryptokit
COMMENT=	Cryptographic primitives library for Objective Caml
LICENSE=	gnu-lgpl-v2 # with static compilation exception

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/ocaml-zarith/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
