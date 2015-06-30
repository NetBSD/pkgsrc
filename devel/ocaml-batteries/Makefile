# $NetBSD: Makefile,v 1.5 2015/06/30 11:52:56 jaapb Exp $

DISTNAME=	batteries-2.3
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1465/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://batteries.forge.ocamlcore.org/
COMMENT=	Alternative standard library for OCaml
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake

MAKE_ENV=	DESTDIR="${DESTDIR}" PREFIX="${PREFIX}"

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
