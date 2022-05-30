# $NetBSD: Makefile,v 1.9 2022/05/30 09:47:34 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.9.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=inhabitedtype/}
GITHUB_PROJECT=	bigstringaf

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/inhabitedtype/bigstringaf/
COMMENT=	Bigstring intrinsics and fast blits based on memcpy/memmmove
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake pkg-config
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-bigarray-compat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
