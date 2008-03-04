# $NetBSD: Makefile,v 1.1.1.1 2008/03/04 12:41:36 adam Exp $

PKGNAME=	postgresql83-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql83-client>=${BASE_VERS}:../../databases/postgresql83-client
DEPENDS+=	postgresql83-server>=${BASE_VERS}:../../databases/postgresql83-server

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
