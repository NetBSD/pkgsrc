# $NetBSD: Makefile,v 1.123 2008/01/04 11:42:29 ghen Exp $

DISTNAME=		openldap-${OPENLDAP_VERSION}
OPENLDAP_VERSION=	2.3.39
CATEGORIES=		databases
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.openldap.org/
COMMENT=		Lightweight Directory Access Protocol meta-package

DEPENDS+=		openldap-client>=${OPENLDAP_VERSION}:../../databases/openldap-client
DEPENDS+=		openldap-server>=${OPENLDAP_VERSION}:../../databases/openldap-server
DEPENDS+=		openldap-doc>=${OPENLDAP_VERSION}:../../databases/openldap-doc

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_ONLY=		# yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
PLIST_SRC=		# empty (meta-package)

do-patch:		# empty
do-install:		# empty

.include "../../mk/bsd.pkg.mk"
