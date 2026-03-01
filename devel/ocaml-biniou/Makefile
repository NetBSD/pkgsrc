# $NetBSD: Makefile,v 1.19 2026/03/01 12:38:21 gdt Exp $

GITHUB_PROJECT=	biniou
DISTNAME=	${GITHUB_PROJECT}-1.2.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
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
