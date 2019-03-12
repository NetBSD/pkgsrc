# $NetBSD: Makefile,v 1.1 2019/03/12 18:09:29 jaapb Exp $

GITHUB_PROJECT=	bigstringaf
DISTNAME=	${GITHUB_PROJECT}-0.4.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=inhabitedtype/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/inhabitedtype/bigstringaf/
COMMENT=	Bigstring intrinsics and fast blits based on memcpy/memmmove
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
