# $NetBSD: Makefile,v 1.26 2017/07/30 22:32:21 wiz Exp $
#

DISTNAME=	ocaml-ssl-0.5.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=savonet/}
PKGREVISION=	1

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/savonet/ocaml-ssl
COMMENT=	SSL library for OCaml
LICENSE=	gnu-lgpl-v2.1

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
