# $NetBSD: Makefile,v 1.65 2001/05/15 15:59:22 jlam Exp $

.include "../../databases/postgresql/Makefile.common"

PKGNAME=	postgresql-${PG_VERS}
PG_PKG_VERS=	# empty
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql-client>=${PG_BASE_VERS}:../../databases/postgresql-client
DEPENDS+=	postgresql-server>=${PG_BASE_VERS}:../../databases/postgresql-server
DEPENDS+=	postgresql-docs>=${PG_BASE_VERS}:../../databases/postgresql-docs

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_PATCH=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
