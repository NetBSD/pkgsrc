# $NetBSD: Makefile,v 1.3 2004/12/28 02:47:50 reed Exp $
#

DISTNAME=		smartmontools-5.32
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=smartmontools/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://smartmontools.sourceforge.net/
COMMENT=		Control and monitor storage systems using SMART

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/smartmontools

CONF_FILES=		${EGDIR}/smartd.conf ${PKG_SYSCONFDIR}/smartd.conf
RCD_SCRIPTS=		smartd

CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/smartmontools

INSTALLATION_DIRS=	${EGDIR}

.include "../../mk/bsd.pkg.mk"
