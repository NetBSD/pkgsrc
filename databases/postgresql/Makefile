# $NetBSD: Makefile,v 1.68 2002/10/19 04:01:22 jlam Exp $

PKGNAME=	postgresql-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql-client>=${BASE_VERS}:../../databases/postgresql-client
DEPENDS+=	postgresql-server>=${BASE_VERS}:../../databases/postgresql-server
DEPENDS+=	postgresql-docs>=${BASE_VERS}:../../databases/postgresql-docs

.include "../../databases/postgresql/Makefile.common"

EXTRACT_ONLY=	# empty
USE_BUILDLINK2=	YES
NO_CHECKSUM=	YES
NO_PATCH=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
