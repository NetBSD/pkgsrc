# $NetBSD: Makefile,v 1.24 2005/04/04 09:31:46 adam Exp $

.include	"../nessus/Makefile.common"

DISTNAME=	nessus-${VERS}
MASTER_SITES=	# empty
DISTFILES=	# empty

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
