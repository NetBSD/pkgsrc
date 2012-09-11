# $NetBSD: Makefile,v 1.26 2012/09/11 23:19:35 asau Exp $
#

DISTNAME=		mtree-20120308
CATEGORIES=		pkgtools sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		sbd@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Utility for mapping and checking directory hierarchies

GNU_CONFIGURE=		yes

USE_FEATURES=		nbcompat

.include "../../mk/bsd.prefs.mk"

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
