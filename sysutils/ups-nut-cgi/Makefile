# $NetBSD: Makefile,v 1.31 2004/10/03 00:18:16 tv Exp $

DISTNAME=		nut-2.0.0
PKGNAME=		ups-nut-cgi-2.0.0
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://random.networkupstools.org/source/2.0/

MAINTAINER=		lukem@NetBSD.org
HOMEPAGE=		http://www.networkupstools.org/
COMMENT=		Network UPS Tools CGI scripts

DEPENDS+=		ups-nut-2.*:../../sysutils/ups-nut

ALL_TARGET=		cgi
INSTALL_TARGET=		install-cgi

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${NUT_CONFDIR}			\
			--datadir=${NUT_DATADIR}			\
			--localstatedir=${NUT_STATEDIR}			\
			--with-statepath=${NUT_STATEDIR}		\
			--with-cgi					\
			--with-cgipath=${NUT_CGIDIR}

PKG_SYSCONFSUBDIR?=	nut
NUT_CONFDIR=		${PKG_SYSCONFDIR}
NUT_DATADIR=		${PREFIX}/share/nut
NUT_EGDIR=		${PREFIX}/share/examples/nut
NUT_STATEDIR=		/var/db/nut
NUT_CGIDIR=		${PREFIX}/libexec/cgi-bin

CONF_FILES=		${NUT_EGDIR}/hosts.conf.sample ${NUT_CONFDIR}/hosts.conf
CONF_FILES+=		${NUT_EGDIR}/upsset.conf.sample \
			${NUT_CONFDIR}/upsset.conf
CONF_FILES+=		${NUT_EGDIR}/upsstats-single.html.sample \
			${NUT_CONFDIR}/upsstats-single.html
CONF_FILES+=		${NUT_EGDIR}/upsstats.html.sample \
			${NUT_CONFDIR}/upsstats.html

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
