# $NetBSD: Makefile,v 1.32 2018/11/12 16:10:16 jaapb Exp $
#

DISTNAME=	ocaml-ssl-0.5.5
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=savonet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/savonet/ocaml-ssl
COMMENT=	SSL library for OCaml
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake
MAKE_JOBS_SAFE=	no

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_REGISTER=	yes

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.prefs.mk"

.include "../../mk/ocaml.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
