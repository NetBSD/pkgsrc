# $NetBSD: Makefile,v 1.29 2020/01/18 23:33:26 rillig Exp $
#

PKGNAME=		mtree-20130908
CATEGORIES=		pkgtools sysutils

MAINTAINER=		sbd@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Utility for mapping and checking directory hierarchies

GNU_CONFIGURE=		yes

USE_FEATURES=		nbcompat

.include "../../mk/bsd.prefs.mk"

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
