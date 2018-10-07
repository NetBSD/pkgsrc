# $NetBSD: Makefile,v 1.24 2018/10/07 22:26:42 maya Exp $

DISTNAME=	miniupnpd-2.1
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/download.php?file=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://miniupnp.free.fr/
COMMENT=	UPnP IGD service with NAT-PMP support
LICENSE=	modified-bsd

EGDIR=		${PREFIX}/share/examples/miniupnpd
CONF_FILES=	${EGDIR}/miniupnpd.conf ${PKG_SYSCONFDIR}/miniupnpd.conf

# miniupnpd.c:9:20: fatal error: config.h: No such file or directory
MAKE_JOBS_SAFE=	no

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
