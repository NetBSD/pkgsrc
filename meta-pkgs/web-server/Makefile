# $NetBSD: Makefile,v 1.2 1998/08/14 10:17:44 frueauf Exp $
#

DISTNAME=	web-server-1.0
CATEGORIES=	www meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org

DEPENDS+=	ap-auth-cookie-1.6:../../www/ap-auth-cookie
DEPENDS+=	apache-1.3.1:../../www/apache
DEPENDS+=	lynx-2.8:../../www/lynx
DEPENDS+=	glimpse-4.0:../../textproc/glimpse

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
