# $NetBSD: Makefile,v 1.21 2012/10/23 19:51:24 asau Exp $

DISTNAME=		smartmontools-5.40
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=smartmontools/}

MAINTAINER=		shattered@NetBSD.org
HOMEPAGE=		http://smartmontools.sourceforge.net/
COMMENT=		Control and monitor storage systems using SMART
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/smartmontools
CONF_FILES=		${EGDIR}/smartd.conf ${PKG_SYSCONFDIR}/smartd.conf
RCD_SCRIPTS=		smartd

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/smartmontools
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

INSTALLATION_DIRS=	${EGDIR}

.include "../../mk/bsd.pkg.mk"
