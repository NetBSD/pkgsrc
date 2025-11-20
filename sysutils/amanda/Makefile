# $NetBSD: Makefile,v 1.49 2025/11/20 13:46:58 wiz Exp $
#

.include	"../../sysutils/amanda-common/version.mk"

DISTNAME=	amanda-${AMANDA_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.amanda.org/
COMMENT=	The "meta-package" for Amanda, a network backup system

META_PACKAGE=	yes

DEPENDS+=	amanda-client-${AMANDA_VERSION}{,nb[0-9]*}:../../sysutils/amanda-client
DEPENDS+=	amanda-server-${AMANDA_VERSION}{,nb[0-9]*}:../../sysutils/amanda-server
DEPENDS+=	amanda-plot-${AMANDA_VERSION}{,nb[0-9]*}:../../sysutils/amanda-plot

.include "../../mk/bsd.pkg.mk"
