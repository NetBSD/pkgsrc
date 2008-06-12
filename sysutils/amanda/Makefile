# $NetBSD: Makefile,v 1.44 2008/06/12 02:14:46 joerg Exp $
#

# XXX get this from ../../sysutils/amanda-common/Makefile.common
VERSION=2.5.2p1

DISTNAME=	amanda-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amanda.org/
COMMENT=	The "meta-package" for Amanda, a network backup system

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	amanda-client-${VERSION}{,nb[0-9]*}:../../sysutils/amanda-client
DEPENDS+=	amanda-server-${VERSION}{,nb[0-9]*}:../../sysutils/amanda-server
DEPENDS+=	amanda-plot-${VERSION}{,nb[0-9]*}:../../sysutils/amanda-plot

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
