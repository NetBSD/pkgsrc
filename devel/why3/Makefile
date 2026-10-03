# $NetBSD: Makefile,v 1.23 2026/10/03 06:56:42 wiz Exp $

DISTNAME=	why3-1.8.2
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	https://why3.gitlabpages.inria.fr/releases/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.why3.org/
COMMENT=	Platform for deductive program verification
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	coq>=8.16:../../lang/coq
DEPENDS+=	menhir-[0-9]*:../../devel/menhir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--disable-emacs-compilation
INSTALL_TARGET=		install install-lib

LDFLAGS.SunOS+=		-lsocket

.include "../../lang/ocaml/buildlink3.mk"
.include "../../archivers/ocaml-zip/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../math/ocaml-zarith/buildlink3.mk"
.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
