# $NetBSD: Makefile,v 1.69 2003/01/05 20:12:07 jlam Exp $

PKGNAME=	postgresql-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql-client>=${BASE_VERS}:../../databases/postgresql-client
DEPENDS+=	postgresql-server>=${BASE_VERS}:../../databases/postgresql-server
DEPENDS+=	postgresql-docs>=${BASE_VERS}:../../databases/postgresql-docs

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_PATCH=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
