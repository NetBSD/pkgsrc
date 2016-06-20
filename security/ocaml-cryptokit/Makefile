# $NetBSD: Makefile,v 1.13 2016/06/20 10:21:52 jaapb Exp $
#

DISTNAME=	cryptokit-1.10
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1493/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/cryptokit/
COMMENT=	Cryptographic primitives library for Objective Caml
LICENSE=	gnu-lgpl-v2 # with static compilation exception

OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"

USE_TOOLS+=	gmake

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
