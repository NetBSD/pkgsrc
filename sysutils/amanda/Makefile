# $NetBSD: Makefile,v 1.23 1999/02/25 15:47:25 bouyer Exp $
#

DISTNAME=	amanda-2.4.1p1
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.amanda.org/

DEPENDS+=	amanda-client-2.4.1p1:../amanda-client
DEPENDS+=	amanda-server-2.4.1p1:../amanda-server

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
