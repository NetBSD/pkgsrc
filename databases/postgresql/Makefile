# $NetBSD: Makefile,v 1.64 2001/05/14 14:52:36 jlam Exp $

.include "../../databases/postgresql/Makefile.common"

PKGNAME=	postgresql-${PG_VERS}
PG_PKG_VERS=	# empty
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql-client>=${PG_BASE_VERS}:../../postgresql-client
DEPENDS+=	postgresql-server>=${PG_BASE_VERS}:../../postgresql-server
DEPENDS+=	postgresql-docs>=${PG_BASE_VERS}:../../postgresql-docs

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_PATCH=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
