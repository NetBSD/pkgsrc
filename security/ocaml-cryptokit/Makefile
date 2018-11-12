# $NetBSD: Makefile,v 1.22 2018/11/12 16:10:16 jaapb Exp $
#

VERSION=	1.11
GITHUB_PROJECT=	cryptokit
GITHUB_TAG=	release${VERSION:S/.//}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=xavierleroy/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/xavierleroy/cryptokit
COMMENT=	Cryptographic primitives library for Objective Caml
LICENSE=	gnu-lgpl-v2 # with static compilation exception

OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"

USE_TOOLS+=	gmake

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/ocaml-zarith/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
