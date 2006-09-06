# $NetBSD: Makefile,v 1.116.2.1 2006/09/06 21:51:04 snj Exp $

DISTNAME=		openldap-${OPENLDAP_VERSION}
OPENLDAP_VERSION=	2.3.27
CATEGORIES=		databases
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.openldap.org/
COMMENT=		Lightweight Directory Access Protocol meta-package

DEPENDS+=		openldap-client>=${OPENLDAP_VERSION}:../../databases/openldap-client
DEPENDS+=		openldap-server>=${OPENLDAP_VERSION}:../../databases/openldap-server
DEPENDS+=		openldap-doc>=${OPENLDAP_VERSION}:../../databases/openldap-doc

EXTRACT_ONLY=		# yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-patch:		# empty
do-install:		# empty

.include "../../mk/bsd.pkg.mk"
