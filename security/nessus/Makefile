# $NetBSD: Makefile,v 1.31 2006/01/29 17:05:54 adam Exp $

.include	"../../security/nessus/Makefile.common"

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
