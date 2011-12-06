# $NetBSD: Makefile,v 1.5 2011/12/06 00:19:23 sbd Exp $
#

DISTNAME=	menhir-20080912
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~fpottier/menhir/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cristal.inria.fr/~fpottier/menhir/
COMMENT=	LR(1) parser generator in OCaml

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

BUILD_DEPENDS+=		ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_TOOLS+=		gmake

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV=		EGDIR=${EGDIR:Q}

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.09

post-extract:
	${RM} ${WRKSRC}/demos/calc/.omakedb*

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
