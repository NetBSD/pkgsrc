# $NetBSD: Makefile,v 1.22 1999/02/24 10:44:51 bouyer Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/27 00:47:46 se Exp
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
