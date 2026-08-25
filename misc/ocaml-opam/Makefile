# $NetBSD: Makefile,v 1.63 2026/08/25 18:07:44 wiz Exp $

DISTNAME=	opam-full-2.5.2
PKGNAME=	ocaml-${DISTNAME:S/-full//}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/opam/releases/download/${PKGVERSION_NOREV}/}

MAINTAINER=	kit-ty-kate@exn.st
HOMEPAGE=	https://opam.ocaml.org/
COMMENT=	OCaml package manager
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	ocaml-dune-[0-9]*:../../devel/ocaml-dune

DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	rsync-[0-9]*:../../net/rsync

MAKE_JOBS_SAFE=	no
USE_LANGUAGES+=	c c++
HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-vendored-deps --with-mccs

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
