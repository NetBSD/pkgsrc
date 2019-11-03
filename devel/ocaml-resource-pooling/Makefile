# $NetBSD: Makefile,v 1.2 2019/11/03 10:39:26 rillig Exp $

GITHUB_PROJECT=	resource-pooling
DISTNAME=	${GITHUB_PROJECT}-0.6
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	https://github.com/ocsigen/resource-pooling/
COMMENT=	Library for pooling resources like connections and threads
LICENSE=	mit

USE_LANGUAGES=		# none
OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
