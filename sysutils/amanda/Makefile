# $NetBSD: Makefile,v 1.26 1999/04/26 19:25:06 garbled Exp $
#

DISTNAME=	amanda-2.4.1p1
PKGNAME=	amanda-all-2.4.1p1
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.amanda.org/

DEPENDS+=	amanda-client-2.4.1p1:../amanda-client
DEPENDS+=	amanda-server-2.4.1p1:../amanda-server

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
