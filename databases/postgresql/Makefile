# $NetBSD: Makefile,v 1.70 2003/03/28 21:14:15 wiz Exp $

PKGNAME=	postgresql-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql-client>=${BASE_VERS}:../../databases/postgresql-client
DEPENDS+=	postgresql-server>=${BASE_VERS}:../../databases/postgresql-server
DEPENDS+=	postgresql-docs>=${BASE_VERS}:../../databases/postgresql-docs

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
