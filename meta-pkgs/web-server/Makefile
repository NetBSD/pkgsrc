# $NetBSD: Makefile,v 1.4 1999/03/07 22:42:06 tron Exp $
#

DISTNAME=	web-server-1.0
CATEGORIES=	meta-pkgs www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org

DEPENDS+=	ap-auth-cookie-1.6:../../www/ap-auth-cookie
DEPENDS+=	apache-1.3.1:../../www/apache
DEPENDS+=	lynx-2.8:../../www/lynx
DEPENDS+=	glimpse-4.1:../../textproc/glimpse

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
