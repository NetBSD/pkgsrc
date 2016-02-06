# $NetBSD: Makefile,v 1.1 2016/02/06 13:28:07 jaapb Exp $

GITHUB_PROJECT=	ocaml-base64
DISTNAME=	${GITHUB_PROJECT}-2.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=mirage/ocaml-base64/}
COMMENT=	Base64 encoding and decoding in OCaml
LICENSE=	isc

WRKSRC=		${WRKDIR}/ocaml-base64-2.0.0
HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
