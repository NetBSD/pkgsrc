# $NetBSD: Makefile,v 1.4 2003/07/21 16:58:18 martti Exp $
#

DISTNAME=	netbsd-www-1.0
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	grant@NetBSD.org
COMMENT=	Meta-pkg including all packages to convert DocBook/XML -> HTML

DEPENDS+=	docbook-website>=2.3nb3:../../textproc/docbook-website
DEPENDS+=	libxslt>=1.0.20:../../textproc/libxslt

EXTRACT_ONLY=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
