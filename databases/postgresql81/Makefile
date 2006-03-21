# $NetBSD: Makefile,v 1.2 2006/03/21 06:39:33 martti Exp $

PKGNAME=	postgresql81-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql81-client>=${BASE_VERS}:../../databases/postgresql81-client
DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
