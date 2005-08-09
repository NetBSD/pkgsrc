# $NetBSD: Makefile,v 1.28 2005/08/09 21:33:23 tron Exp $

.include	"../nessus/Makefile.common"

DISTNAME=	nessus-${VERS}
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	The Nessus Network Security Scanner

DEPENDS+=	nessus-plugins-${VERS}{,nb*}:../../security/nessus-plugins

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
