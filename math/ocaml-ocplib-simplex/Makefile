# $NetBSD: Makefile,v 1.3 2026/03/01 12:38:36 gdt Exp $

VERSION=	0.5.1
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=OCamlPro/}
GITHUB_PROJECT=	ocplib-simplex
GITHUB_TAG=	v${VERSION}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/OCamlPro/ocplib-simplex
COMMENT=	Ocplib-simplex library implements a simplex algorithm
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		gmake
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/ocplib-simplex

OCAML_USE_DUNE=		yes
OCAML_USE_FINDLIB=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-logs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
