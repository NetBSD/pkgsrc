# $NetBSD: Makefile,v 1.1.1.1 2006/12/09 15:34:13 adam Exp $

PKGNAME=	postgresql82-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql82-client>=${BASE_VERS}:../../databases/postgresql82-client
DEPENDS+=	postgresql82-server>=${BASE_VERS}:../../databases/postgresql82-server

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
