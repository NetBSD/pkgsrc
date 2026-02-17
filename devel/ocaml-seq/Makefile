# $NetBSD: Makefile,v 1.7 2026/02/17 13:39:07 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.2.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=c-cube/}
GITHUB_PROJECT=	seq

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/c-cube/seq/
COMMENT=	Ocaml seq library compatibility package
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
