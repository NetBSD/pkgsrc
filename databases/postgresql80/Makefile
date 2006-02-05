# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:35 joerg Exp $

PKGNAME=	postgresql80-${BASE_VERS}
PKGREVISION=	1
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
