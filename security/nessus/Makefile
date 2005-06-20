# $NetBSD: Makefile,v 1.26 2005/06/20 15:47:57 tron Exp $

.include	"../nessus/Makefile.common"

DISTNAME=	nessus-${VERS}
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	The Nessus Network Security Scanner

DEPENDS+=	nessus-core-${VERS}{,nb*}:../nessus-core
DEPENDS+=	nessus-plugins-${VERS}{,nb*}:../nessus-plugins

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
