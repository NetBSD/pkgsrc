# $NetBSD: Makefile,v 1.2 2001/02/05 09:01:04 tron Exp $
#

DISTNAME=		nut-0.44.2
PKGNAME=		ups-nut-cgi-0.44.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.exploits.org/nut/release/

MAINTAINER=		collver@softhome.net
HOMEPAGE=		http://www.exploits.org/nut/

DEPENDS+=		gd-*:../../graphics/gd
DEPENDS+=		ups-nut-0*:../ups-nut
BUILD_DEPENDS+=		${LOCALBASE}/bin/${LOCALBASE}/bin/autoremake:../../devel/autoconf

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
