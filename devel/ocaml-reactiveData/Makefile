# $NetBSD: Makefile,v 1.16 2022/05/10 08:14:02 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.3
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}
GITHUB_PROJECT=	reactiveData

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/reactiveData
COMMENT=	Functional reactive programming library
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-react/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
