# $NetBSD: Makefile,v 1.19 2016/02/03 12:48:38 jaapb Exp $
#

PKGNAME=	${DISTNAME} # to avoid prefixing with ocaml-
DISTNAME=	ocaml-ssl-0.5.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=savonet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://github.com/savonet/ocaml-ssl
COMMENT=	SSL library for OCaml
LICENSE=	gnu-lgpl-v2.1

# ssl.cmo used before written
MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_REGISTER=	yes

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.prefs.mk"

.include "../../mk/ocaml.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
