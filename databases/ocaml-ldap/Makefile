# $NetBSD: Makefile,v 1.4 2017/07/11 14:19:19 jaapb Exp $

VERSION=	2.2
PKGNAME=	ocaml-ldap-${VERSION}
PKGREVISION=	2
DISTNAME=	ocamldap-${VERSION}
CATEGORIES=	databases
MASTER_SITES=	http://bitbucket.org/deplai_j/ocamldap/downloads/

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
