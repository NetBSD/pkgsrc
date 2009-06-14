# $NetBSD: Makefile,v 1.2 2009/06/14 18:43:37 joerg Exp $
#

DISTNAME=	menhir-20080912
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~fpottier/menhir/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://cristal.inria.fr/~fpottier/menhir/
COMMENT=	LR(1) parser generator in OCaml

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_TOOLS+=		gmake

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV=		EGDIR=${EGDIR:Q}

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.09

post-extract:
	${RM} ${WRKSRC}/demos/calc/.omakedb*

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
