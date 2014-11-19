# $NetBSD: Makefile,v 1.1 2014/11/19 12:00:48 jaapb Exp $

VERSION=	1.0.0
PKGNAME=	ocaml-ipaddr-${VERSION}
DISTNAME=	v${VERSION}
DIST_SUBDIR=	ocaml-ipaddr
CATEGORIES=	net
MASTER_SITES=	https://github.com/mirage/ocaml-ipaddr/archive/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-ipaddr/
COMMENT=	Library for manipulation of IP and MAC addresses
LICENSE=	isc

WRKSRC=		${WRKDIR}/ocaml-ipaddr-${VERSION}

OCAML_USE_FINDLIB=	yes
OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
