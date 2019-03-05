# $NetBSD: Makefile,v 1.12 2019/03/05 17:37:10 jaapb Exp $

GITHUB_PROJECT=	biniou
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.2.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mjambon/biniou/
COMMENT=	Extensible binary data format, like JSON but faster
LICENSE=	modified-bsd

OCAML_USE_DUNE=	yes
INSTALLATION_DIRS+=	bin

.include "../../mk/ocaml.mk"
.include "../../textproc/ocaml-easy-format/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
