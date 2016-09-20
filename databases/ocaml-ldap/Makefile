# $NetBSD: Makefile,v 1.1 2016/09/20 12:52:59 jaapb Exp $

DISTNAME=	ocamldap-2.2
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
