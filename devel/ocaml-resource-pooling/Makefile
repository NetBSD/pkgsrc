# $NetBSD: Makefile,v 1.7 2026/02/17 13:39:06 wiz Exp $

GITHUB_PROJECT=	resource-pooling
DISTNAME=	${GITHUB_PROJECT}-1.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	pkgsrc-users@kerguelen.org
HOMEPAGE=	https://github.com/ocsigen/resource-pooling/
COMMENT=	Library for pooling resources like connections and threads
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
