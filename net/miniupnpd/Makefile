# $NetBSD: Makefile,v 1.9 2013/10/21 10:06:57 fhajny Exp $

DISTNAME=	miniupnpd-1.8.20130730
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
