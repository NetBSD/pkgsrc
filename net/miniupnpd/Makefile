# $NetBSD: Makefile,v 1.20 2016/03/01 13:14:52 adam Exp $

DISTNAME=	miniupnpd-1.9.20160222
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/download.php?file=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://miniupnp.free.fr/
COMMENT=	UPnP IGD service with NAT-PMP support
LICENSE=	modified-bsd

EGDIR=		${PREFIX}/share/examples/miniupnpd
CONF_FILES=	${EGDIR}/miniupnpd.conf ${PKG_SYSCONFDIR}/miniupnpd.conf

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CFLAGS+=	-DDEFAULT_CONFIG=\"${PKG_SYSCONFDIR}/miniupnpd.conf\"

INSTALL_MAKE_FLAGS+=	INSTALLETCDIR=${EGDIR}
INSTALL_MAKE_FLAGS+=	INSTALLMANDIR=${PREFIX}/${PKGMANDIR}/man1

RCD_SCRIPTS=	miniupnpd

SUBST_CLASSES+=		fwname
SUBST_STAGE.fwname=	pre-configure
SUBST_MESSAGE.fwname=	Setting desired firewall type.
SUBST_FILES.fwname=	genconfig.sh
SUBST_VARS.fwname=	FWNAME

.include "../../mk/bsd.pkg.mk"
