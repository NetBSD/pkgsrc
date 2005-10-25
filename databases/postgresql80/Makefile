# $NetBSD: Makefile,v 1.7 2005/10/25 09:54:26 abs Exp $

PKGNAME=	postgresql80-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql80-client>=${BASE_VERS}:../../databases/postgresql80-client
DEPENDS+=	postgresql80-server>=${BASE_VERS}:../../databases/postgresql80-server

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
