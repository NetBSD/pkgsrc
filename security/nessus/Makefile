# $NetBSD: Makefile,v 1.14 2003/05/02 11:56:18 wiz Exp $
#

DISTNAME=	nessus-${VERS}
PKGREVISION=	1
MASTER_SITES=	# empty
DISTFILES=	# empty
.include	"../nessus/Makefile.common"

COMMENT=	The Nessus Network Security Scanner

DEPENDS+=	nessus-core-${VERS}nb1:../nessus-core
DEPENDS+=	nessus-plugins-${VERS}nb1:../nessus-plugins

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
