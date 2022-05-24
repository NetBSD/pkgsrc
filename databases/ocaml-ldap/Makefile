# $NetBSD: Makefile,v 1.17 2022/05/24 18:59:20 jaapb Exp $

VERSION=	2.4.2
GITHUB_PROJECT=	ocamldap
GITHUB_TAG=	${VERSION}
PKGNAME=	ocaml-ldap-${VERSION}
DISTNAME=	ocamldap-${VERSION}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=kit-ty-kate/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/kit-ty-kate/ocamldap
COMMENT=	OCamL implementation of the LDAP protocol
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		# none
OCAML_USE_DUNE=		yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
