# $NetBSD: Makefile,v 1.1.1.1 2004/07/24 22:14:40 recht Exp $

PKGNAME=	postgresql73-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql73-client>=${BASE_VERS}:../../databases/postgresql73-client
DEPENDS+=	postgresql73-server>=${BASE_VERS}:../../databases/postgresql73-server
DEPENDS+=	postgresql73-docs>=${BASE_VERS}:../../databases/postgresql73-docs

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
