# $NetBSD: Makefile,v 1.5 2004/08/04 13:55:02 recht Exp $

PKGNAME=	postgresql74-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql74-client>=${BASE_VERS}nb1:../../databases/postgresql74-client
DEPENDS+=	postgresql74-server>=${BASE_VERS}:../../databases/postgresql74-server
DEPENDS+=	postgresql74-docs>=${BASE_VERS}:../../databases/postgresql74-docs

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
