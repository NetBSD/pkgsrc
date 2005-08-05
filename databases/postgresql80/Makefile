# $NetBSD: Makefile,v 1.5 2005/08/05 19:43:44 jlam Exp $

PKGNAME=	postgresql80-${BASE_VERS}
PKGREVISION=	1
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
