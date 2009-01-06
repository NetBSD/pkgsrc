# $NetBSD: Makefile,v 1.2 2009/01/06 23:39:53 jmcneill Exp $
#

DISTNAME=	miniupnpd-20081009
PKGNAME=	${DISTNAME:S/miniupnpd-/&1.2.0./}
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
MAKE_ENV+=	PKG_CFLAGS="-DPKG_DEFAULT_CONFIG=\\\"${PKG_SYSCONFDIR:Q}/miniupnpd.conf\\\""

RCD_SCRIPTS=	miniupnpd

.include "../../mk/bsd.pkg.mk"
