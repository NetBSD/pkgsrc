# $NetBSD: Makefile,v 1.20 2026/03/01 12:38:32 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}
GITHUB_PROJECT=	reactiveData

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/reactiveData
COMMENT=	Functional reactive programming library
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-react/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
