# $NetBSD: Makefile,v 1.16 2022/05/24 18:51:47 jaapb Exp $

GITHUB_PROJECT=	biniou
DISTNAME=	${GITHUB_PROJECT}-1.2.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-community/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-community/biniou/
COMMENT=	Extensible binary data format, like JSON but faster
LICENSE=	modified-bsd

OCAML_USE_DUNE=		yes
INSTALLATION_DIRS+=	bin

.include "../../lang/ocaml/ocaml.mk"
.include "../../textproc/ocaml-easy-format/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
