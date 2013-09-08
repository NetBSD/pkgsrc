# $NetBSD: Makefile,v 1.27 2013/09/08 16:20:10 ryoon Exp $
#

DISTNAME=		mtree-20130908
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
