# $NetBSD: Makefile,v 1.28 2022/05/24 18:59:35 jaapb Exp $
#

VERSION=	4.5.0
GITHUB_PROJECT=	tyxml
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://ocsigen.org/tyxml/
COMMENT=	OCaml XML typing library
LICENSE=	gnu-lgpl-v2.1 # with openssl exemption

CONFLICTS+=	ocsigen<2.0

CONFIGURE_ARGS+=	--enable-syntax --bindir ${DESTDIR}${PREFIX}/bin

USE_TOOLS=	gmake
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../textproc/ocaml-markup/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
