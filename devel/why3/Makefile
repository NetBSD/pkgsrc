# $NetBSD: Makefile,v 1.16 2026/03/01 12:38:34 gdt Exp $

DISTNAME=	why3-1.8.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://why3.gitlabpages.inria.fr/releases/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.why3.org/
COMMENT=	Platform for deductive program verification
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	menhir-[0-9]*:../../devel/menhir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--disable-emacs-compilation
INSTALL_TARGET=		install install-lib

DEPENDS+=		coq>=8.16:../../lang/coq

.include "../../lang/ocaml/buildlink3.mk"
.include "../../archivers/ocaml-zip/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../math/ocaml-zarith/buildlink3.mk"
.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
