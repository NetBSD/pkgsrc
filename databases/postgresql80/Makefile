# $NetBSD: Makefile,v 1.6 2005/10/23 20:16:52 jlam Exp $

PKGNAME=	postgresql80-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql80-client>=${BASE_VERS}nb2:../../databases/postgresql80-client
DEPENDS+=	postgresql80-server>=${BASE_VERS}nb2:../../databases/postgresql80-server

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
