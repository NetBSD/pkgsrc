# $NetBSD: Makefile,v 1.10 2016/02/06 12:51:34 jaapb Exp $
#

DISTNAME=	tyxml-${VERSION}
VERSION=	3.6.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}
GITHUB_PROJECT=	tyxml

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocsigen.org/tyxml/
COMMENT=	OCaml XML typing library
LICENSE=	gnu-lgpl-v2.1 # with openssl exemption

CONFLICTS+=	ocsigen<2.0

WRKSRC=	${WRKDIR}/tyxml-${VERSION}
MAKE_ENV+=	INSTALLDIR="${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}"

USE_TOOLS=	gmake
OCAML_USE_FINDLIB=	yes
OCAML_USE_OASIS=	yes


.include "../../mk/ocaml.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
#.include "../../net/ocamlnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
