# $NetBSD: Makefile,v 1.125 2008/01/13 17:15:16 ghen Exp $

DISTNAME=		openldap-${OPENLDAP_VERSION}
OPENLDAP_VERSION=	2.4.7
CATEGORIES=		databases
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.openldap.org/
COMMENT=		Lightweight Directory Access Protocol meta-package

META_PACKAGE=		yes

DEPENDS+=		openldap-client>=${OPENLDAP_VERSION}:../../databases/openldap-client
DEPENDS+=		openldap-server>=${OPENLDAP_VERSION}:../../databases/openldap-server
DEPENDS+=		openldap-doc>=${OPENLDAP_VERSION}:../../databases/openldap-doc

.include "../../mk/bsd.pkg.mk"
