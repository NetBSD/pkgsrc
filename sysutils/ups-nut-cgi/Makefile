# $NetBSD: Makefile,v 1.12 2001/11/28 08:18:29 jmc Exp $

DISTNAME=		nut-0.45.2
PKGNAME=		ups-nut-cgi-0.45.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.exploits.org/nut/release/

MAINTAINER=		lukem@netbsd.org
HOMEPAGE=		http://www.exploits.org/nut/
COMMENT=		Network UPS Tools CGI scripts

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf
DEPENDS+=		ups-nut-0.*:../../sysutils/ups-nut

ALL_TARGET=		cgi
INSTALL_TARGET=		install-cgi

NUT_CONFDIR=		${CONFDIR}/nut
NUT_STATEDIR=		/var/db/nut
NUT_CGIDIR=		${PREFIX}/share/nut/cgi

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${NUT_CONFDIR}			\
			--with-statepath=${NUT_STATEDIR}		\
			--with-cgipath=${NUT_CGIDIR}			\
			--with-graphics=${LOCALBASE}

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoreconf --force

.include "../../graphics/gd/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
