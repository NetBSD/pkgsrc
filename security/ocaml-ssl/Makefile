# $NetBSD: Makefile,v 1.15 2015/01/20 14:24:37 jaapb Exp $
#

PKGNAME=	${DISTNAME} # to avoid prefixing with ocaml-
DISTNAME=	ocaml-ssl-0.4.7
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=savonet/}

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://savonet.sourceforge.net/wiki/OCamlLibs
COMMENT=	SSL library for OCaml
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../mk/ocaml.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
