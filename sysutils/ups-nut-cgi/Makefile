# $NetBSD: Makefile,v 1.10 2001/11/18 00:57:50 lukem Exp $

DISTNAME=		nut-0.45.2
PKGNAME=		ups-nut-cgi-0.45.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.exploits.org/nut/release/

MAINTAINER=		lukem@netbsd.org
HOMEPAGE=		http://www.exploits.org/nut/
COMMENT=		Network UPS Tools CGI scripts

DEPENDS+=		gd-[0-9]*:../../graphics/gd
DEPENDS+=		ups-nut-0*:../ups-nut
BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

ALL_TARGET=		cgi
INSTALL_TARGET=		install-cgi

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${LOCALBASE}/etc/nut \
			--with-statepath=/var/db/nut \
			--with-cgipath=${LOCALBASE}/share/nut/cgi \
			--with-graphics=${LOCALBASE}

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoreconf --force

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
