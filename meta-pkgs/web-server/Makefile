# $NetBSD: Makefile,v 1.11 2001/12/03 17:56:55 wiz Exp $
#

DISTNAME=	web-server-1.1
CATEGORIES=	meta-pkgs www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
COMMENT=	provides some useful tools for a web server

DEPENDS+=	apache-1.3.*:../../www/apache
DEPENDS+=	lynx>=2.8.2:../../www/lynx
DEPENDS+=	glimpse>=4.1:../../textproc/glimpse

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
