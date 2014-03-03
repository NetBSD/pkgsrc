# $NetBSD: Makefile,v 1.28 2014/03/03 03:30:53 obache Exp $
#

PKGNAME=		mtree-20130908
CATEGORIES=		pkgtools sysutils

MAINTAINER=		sbd@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Utility for mapping and checking directory hierarchies

GNU_CONFIGURE=		yes

USE_FEATURES=		nbcompat

.include "../../mk/bsd.prefs.mk"

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
