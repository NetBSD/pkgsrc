# $NetBSD: Makefile,v 1.16 2018/01/07 21:02:29 joerg Exp $

VERSION=	2.0
GITHUB_PROJECT=	ocaml-csv
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Chris00/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://csv.forge.ocamlcore.org/
COMMENT=	CSV library for OCaml
LICENSE=	gnu-lgpl-v2.1

#HAS_CONFIGURE=	yes
USE_LANGUAGES=	c

OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
