# $NetBSD: Makefile,v 1.2 2019/11/03 10:39:24 rillig Exp $

GITHUB_PROJECT=	ocplib-endian
DISTNAME=	${GITHUB_PROJECT}-1.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OCamlPro/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/OCamlPro/ocplib-endian/
COMMENT=	Optimised functions to read and write int16/32/64
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		# none
OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
