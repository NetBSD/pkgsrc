# $NetBSD: Makefile,v 1.46 2012/07/30 06:57:21 sbd Exp $
#

.include	"../../sysutils/amanda-common/version.mk"

DISTNAME=	amanda-${AMANDA_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
# MAINTAINER sort-of gdt@NetBSD.org
HOMEPAGE=	http://www.amanda.org/
COMMENT=	The "meta-package" for Amanda, a network backup system

META_PACKAGE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	amanda-client-${AMANDA_VERSION}{,nb[0-9]*}:../../sysutils/amanda-client
DEPENDS+=	amanda-server-${AMANDA_VERSION}{,nb[0-9]*}:../../sysutils/amanda-server
DEPENDS+=	amanda-plot-${AMANDA_VERSION}{,nb[0-9]*}:../../sysutils/amanda-plot

.include "../../mk/bsd.pkg.mk"
