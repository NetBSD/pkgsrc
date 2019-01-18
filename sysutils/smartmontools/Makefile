# $NetBSD: Makefile,v 1.35 2019/01/18 02:05:50 tnn Exp $

DISTNAME=		smartmontools-7.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=smartmontools/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://smartmontools.sourceforge.net/
COMMENT=		Control and monitor storage systems using SMART
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

USE_LANGUAGES=		c c++03
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

OWN_DIRS=		${PKG_SYSCONFDIR}/smartd_warning.d

EGDIR=			${PREFIX}/share/examples/smartmontools
CONF_FILES=		${EGDIR}/smartd.conf ${PKG_SYSCONFDIR}/smartd.conf
CONF_FILES_PERMS=	${EGDIR}/smartd_warning.sh \
			${PKG_SYSCONFDIR}/smartd_warning.sh \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755
RCD_SCRIPTS=		smartd

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/smartmontools
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

INSTALLATION_DIRS=	${EGDIR}

.include "../../mk/bsd.pkg.mk"
