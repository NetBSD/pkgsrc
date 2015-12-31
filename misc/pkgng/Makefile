# $NetBSD: Makefile,v 1.1.1.1 2015/12/31 18:29:50 agc Exp $

DISTNAME=	pkg-1.6.2
CATEGORIES=	misc
MASTER_SITES=	http://files.etoilebsd.net/pkg/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.freebsd.org/pkgng
COMMENT=	FreeBSD's binary package manager
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM+= NetBSD-*-* FreeBSD-*-* DragonFly-*-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-maintainer-mode
USE_LIBTOOL=	yes

AUTO_MKDIRS=	yes

OWN_DIRS+=	${PKG_SYSCONFDIR}/bash_completion.d
OWN_DIRS+=	${PKG_SYSCONFDIR}/periodic/daily
OWN_DIRS+=	${PKG_SYSCONFDIR}/periodic/security
OWN_DIRS+=	${PKG_SYSCONFDIR}/periodic/weekly

EGDIR=		${PREFIX}/share/doc/pkgng
CONF_FILES+=	${EGDIR}/bash_completion.d/_pkg.bash ${PKG_SYSCONFDIR}/periodic/daily/_pkg.bash
CONF_FILES+=	${EGDIR}/periodic/daily/411.pkg-backup ${PKG_SYSCONFDIR}/periodic/daily/411.pkg-backup
CONF_FILES+=	${EGDIR}/periodic/daily/490.status-pkg-changes ${PKG_SYSCONFDIR}/periodic/daily/490.status-pkg-changes
CONF_FILES+=	${EGDIR}/periodic/security/410.pkg-audit ${PKG_SYSCONFDIR}/periodic/security/410.pkg-audit
CONF_FILES+=	${EGDIR}/periodic/security/460.pkg-checksum ${PKG_SYSCONFDIR}/periodic/security/460.pkg-checksum
CONF_FILES+=	${EGDIR}/periodic/weekly/400.status-pkg ${PKG_SYSCONFDIR}/periodic/weekly/400.status-pkg
CONF_FILES+=	${EGDIR}/pkg.conf.sample ${PKG_SYSCONFDIR}/pkg.conf

.include "../../mk/bsd.pkg.mk"
