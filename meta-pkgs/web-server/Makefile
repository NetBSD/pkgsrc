# $NetBSD: Makefile,v 1.21 2007/10/25 22:00:58 jlam Exp $
#

DISTNAME=	web-server-1.1
PKGREVISION=	3
CATEGORIES=	meta-pkgs www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provides some useful tools for a web server

DEPENDS+=	apache-1.3.*:../../www/apache
DEPENDS+=	lynx>=2.8.2:../../www/lynx
DEPENDS+=	glimpse>=4.1:../../textproc/glimpse

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
