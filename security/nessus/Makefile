# $NetBSD: Makefile,v 1.23 2005/01/19 08:40:10 frueauf Exp $

DISTNAME=	nessus-${VERS}
MASTER_SITES=	# empty
DISTFILES=	# empty
.include	"../nessus/Makefile.common"

COMMENT=	The Nessus Network Security Scanner

DEPENDS+=	nessus-core-${VERS}:../nessus-core
DEPENDS+=	nessus-plugins-${VERS}:../nessus-plugins

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
