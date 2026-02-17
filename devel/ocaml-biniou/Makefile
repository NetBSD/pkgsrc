# $NetBSD: Makefile,v 1.18 2026/02/17 13:38:56 wiz Exp $

GITHUB_PROJECT=	biniou
DISTNAME=	${GITHUB_PROJECT}-1.2.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-community/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-community/biniou/
COMMENT=	Extensible binary data format, like JSON but faster
LICENSE=	modified-bsd

OCAML_USE_DUNE=		yes
INSTALLATION_DIRS+=	bin

.include "../../lang/ocaml/ocaml.mk"
.include "../../textproc/ocaml-easy-format/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
