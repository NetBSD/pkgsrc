# $NetBSD: Makefile,v 1.7 2015/01/20 14:24:37 jaapb Exp $
#

DISTNAME=	cryptokit-1.9
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1229/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/cryptokit/
COMMENT=	Cryptographic primitives library for Objective Caml
LICENSE=	gnu-lgpl-v2 # with static compilation exception

OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"

USE_TOOLS+=	gmake

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
