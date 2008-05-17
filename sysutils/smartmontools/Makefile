# $NetBSD: Makefile,v 1.15 2008/05/17 13:07:54 obache Exp $

DISTNAME=		smartmontools-5.38
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=smartmontools/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://smartmontools.sourceforge.net/
COMMENT=		Control and monitor storage systems using SMART

ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

PKG_DESTDIR_SUPPORT=	user-destdir
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
