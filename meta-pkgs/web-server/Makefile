# $NetBSD: Makefile,v 1.16 2004/02/22 20:48:16 jmmv Exp $
#

DISTNAME=	web-server-1.1
CATEGORIES=	meta-pkgs www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Provides some useful tools for a web server

DEPENDS+=	apache-1.3.*:../../www/apache
DEPENDS+=	lynx>=2.8.2:../../www/lynx
DEPENDS+=	glimpse>=4.1:../../textproc/glimpse

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
