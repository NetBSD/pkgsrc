# $NetBSD: Makefile,v 1.1.1.1 2004/04/19 00:07:12 recht Exp $

PKGNAME=	postgresql-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql-client>=${BASE_VERS}:../../databases/postgresql74-client
DEPENDS+=	postgresql-server>=${BASE_VERS}:../../databases/postgresql74-server
DEPENDS+=	postgresql-docs>=${BASE_VERS}:../../databases/postgresql74-docs

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
