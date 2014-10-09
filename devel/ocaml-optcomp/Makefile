# $NetBSD: Makefile,v 1.4 2014/10/09 21:08:51 jaapb Exp $

VERSION=	1.6
DISTNAME=	${VERSION}
PKGNAME=	ocaml-optcomp-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/diml/optcomp/archive/
DIST_SUBDIR=	ocaml-optcomp
WRKSRC=	${WRKDIR}/optcomp-${VERSION}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://github.com/diml/optcomp/
COMMENT=	OCaml syntax extension for optional compilation
LICENSE=	modified-bsd

SUPERSEDES=	optcomp-[0-9]*

OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
