# $NetBSD: Makefile,v 1.1.1.1 2000/12/28 16:07:51 martin Exp $
#

DISTNAME=		nut-0.44.2
PKGNAME=		ups-nut-cgi-0.44.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.exploits.org/nut/release/

MAINTAINER=		collver@softhome.net
HOMEPAGE=		http://www.exploits.org/nut/

DEPENDS+=		gd-*:../../graphics/gd
DEPENDS+=		ups-nut-0*:../ups-nut
BUILD_DEPENDS+=		${LOCALBASE}/bin/autoreconf:../../devel/autoconf

WRKSRC=			${WRKDIR}/nut-0.44.2

ALL_TARGET=		cgi
INSTALL_TARGET=		install-cgi

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${LOCALBASE}/etc/nut \
			--with-state-path=/var/db \
			--with-cgipath=${LOCALBASE}/share/nut/cgi \
			--with-graphics=${LOCALBASE}

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoreconf --force

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
