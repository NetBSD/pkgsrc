# $NetBSD: Makefile,v 1.5 2001/03/11 13:50:50 martin Exp $
#

DISTNAME=		nut-0.44.3-pre5
PKGNAME=		ups-nut-cgi-0.44.3pre5
CATEGORIES=		sysutils
MASTER_SITES=		http://www.exploits.org/nut/testing/0.44.3-pre/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.exploits.org/nut/
COMMENT=		Network UPS Tools CGI scripts

DEPENDS+=		gd-*:../../graphics/gd
DEPENDS+=		ups-nut-0*:../ups-nut
BUILD_DEPENDS+=		${LOCALBASE}/bin/autoreconf:../../devel/autoconf

WRKSRC=			${WRKDIR}/nut-0.44.3

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
