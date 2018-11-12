# $NetBSD: Makefile,v 1.10 2018/11/12 16:10:17 jaapb Exp $

VERSION=	2.3.0
GITHUB_PROJECT=	ocamldap
GITHUB_TAG=	${VERSION}
PKGNAME=	ocaml-ldap-${VERSION}
PKGREVISION=	5
DISTNAME=	ocamldap-${VERSION}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=jpdeplaix/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocamldap.sourceforge.net/
COMMENT=	OCamL implementation of the LDAP protocol
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
