# $NetBSD: Makefile,v 1.1.1.1 2004/07/15 20:17:45 xtraeme Exp $
#

DISTNAME=		smartmontools-5.32
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=smartmontools/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://smartmontools.sourceforge.net/
COMMENT=		Control and monitor storage systems using SMART

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
