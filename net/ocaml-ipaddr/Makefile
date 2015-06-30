# $NetBSD: Makefile,v 1.3 2015/06/30 11:52:58 jaapb Exp $

VERSION=	2.5.0
PKGNAME=	ocaml-ipaddr-${VERSION}
PKGREVISION=	1
DISTNAME=	${VERSION}
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

.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
