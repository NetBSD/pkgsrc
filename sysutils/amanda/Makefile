# $NetBSD: Makefile,v 1.45 2009/02/24 14:53:08 gdt Exp $
#

# XXX get this from ../../sysutils/amanda-common/Makefile.common
VERSION=2.5.2p1

DISTNAME=	amanda-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
# MAINTAINER sort-of gdt@NetBSD.org
HOMEPAGE=	http://www.amanda.org/
COMMENT=	The "meta-package" for Amanda, a network backup system

META_PACKAGE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	amanda-client-${VERSION}{,nb[0-9]*}:../../sysutils/amanda-client
DEPENDS+=	amanda-server-${VERSION}{,nb[0-9]*}:../../sysutils/amanda-server
DEPENDS+=	amanda-plot-${VERSION}{,nb[0-9]*}:../../sysutils/amanda-plot

.include "../../mk/bsd.pkg.mk"
