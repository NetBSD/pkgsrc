# $NetBSD: Makefile,v 1.8 2012/11/20 11:21:59 abs Exp $

DISTNAME=	miniupnpd-1.6.20120320
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/download.php?file=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://miniupnp.free.fr/
COMMENT=	UPnP IGD service with NAT-PMP support
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=	no

EGDIR=		${PREFIX}/share/examples/miniupnpd
CONF_FILES=	${EGDIR}/miniupnpd.conf ${PKG_SYSCONFDIR}/miniupnpd.conf

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CFLAGS+=	-DDEFAULT_CONFIG=\"${PKG_SYSCONFDIR:Q}/miniupnpd.conf\"

INSTALL_MAKE_FLAGS+=	INSTALLETCDIR=${EGDIR}
INSTALL_MAKE_FLAGS+=	INSTALLMANDIR=${PREFIX}/${PKGMANDIR}/man1

RCD_SCRIPTS=	miniupnpd

.include "../../mk/bsd.pkg.mk"
