# $NetBSD: Makefile,v 1.6 2025/03/03 03:27:04 dholland Exp $

DISTNAME=	why3-1.8.0
CATEGORIES=	devel
MASTER_SITES=	https://why3.gitlabpages.inria.fr/releases/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://why3.lri.fr/
COMMENT=	Platform for deductive program verification
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	menhir-[0-9]*:../../devel/menhir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALL_TARGET=		install install-lib

DEPENDS+=		coq>=8.16:../../lang/coq

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../math/ocaml-zarith/buildlink3.mk"
.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
