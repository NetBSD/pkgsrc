# $NetBSD: Makefile,v 1.10 2017/09/08 09:51:21 jaapb Exp $

DISTNAME=	data-notation-${VERSION}
PKGNAME=	ocaml-odn-${VERSION}
VERSION=	0.0.11
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/1310/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/odn
COMMENT=	Data dumping library for OCaml
LICENSE=	gnu-lgpl-v2.1

WRKSRC=	${WRKDIR}/ocaml-${DISTNAME}

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
