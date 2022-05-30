# $NetBSD: Makefile,v 1.8 2022/05/30 09:33:00 jaapb Exp $

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

MAKE_JOBS_SAFE=	no # possible problem with building lib/freestanding
USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-bigarray-compat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
