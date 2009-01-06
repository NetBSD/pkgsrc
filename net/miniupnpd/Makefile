# $NetBSD: Makefile,v 1.1.1.1 2009/01/06 03:56:45 jmcneill Exp $
#

DISTNAME=	miniupnpd-20081009
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/download.php?file=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://miniupnp.free.fr/
COMMENT=	UPnP IGD service with NAT-PMP support

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=		${PREFIX}/share/examples/miniupnpd
CONF_FILES=	${EGDIR}/miniupnpd.conf ${PKG_SYSCONFDIR}/miniupnpd.conf

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

MAKE_ENV+=	${BSD_MAKE_ENV}

.include "../../mk/bsd.pkg.mk"
