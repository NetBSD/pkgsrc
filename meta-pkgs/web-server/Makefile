# $NetBSD: Makefile,v 1.5 1999/04/06 02:03:00 abs Exp $
#

DISTNAME=	web-server-1.0
CATEGORIES=	meta-pkgs www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org

DEPENDS+=	ap-auth-cookie-1.6.1:../../www/ap-auth-cookie
DEPENDS+=	apache-1.3.3.2:../../www/apache
DEPENDS+=	lynx-2.8.1:../../www/lynx
DEPENDS+=	glimpse-4.1:../../textproc/glimpse

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
