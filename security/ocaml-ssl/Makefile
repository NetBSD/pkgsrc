# $NetBSD: Makefile,v 1.44 2026/02/17 13:39:12 wiz Exp $
#

DISTNAME=	ocaml-ssl-0.5.10
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=savonet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/savonet/ocaml-ssl
COMMENT=	SSL library for OCaml
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
