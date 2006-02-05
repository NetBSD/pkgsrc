# $NetBSD: Makefile,v 1.7 2006/02/05 23:08:34 joerg Exp $

PKGNAME=	postgresql74-${BASE_VERS}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql74-client>=${BASE_VERS}:../../databases/postgresql74-client
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
