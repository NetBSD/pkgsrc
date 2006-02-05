# $NetBSD: Makefile,v 1.32 2006/02/05 23:10:45 joerg Exp $

.include	"../../security/nessus/Makefile.common"

DISTNAME=	nessus-${VERS}
PKGREVISION=	1
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
