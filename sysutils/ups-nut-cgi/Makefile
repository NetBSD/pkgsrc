# $NetBSD: Makefile,v 1.20 2002/12/13 04:23:20 lukem Exp $

DISTNAME=		nut-1.2.1
PKGNAME=		ups-nut-cgi-1.2.1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.exploits.org/nut/release/1.2/

MAINTAINER=		lukem@netbsd.org
HOMEPAGE=		http://www.exploits.org/nut/
COMMENT=		Network UPS Tools CGI scripts

DEPENDS+=		ups-nut-1.*:../../sysutils/ups-nut

ALL_TARGET=		cgi
INSTALL_TARGET=		install-cgi

USE_BUILDLINK2=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${NUT_CONFDIR}			\
			--with-statepath=${NUT_STATEDIR}		\
			--with-cgi					\
			--with-cgipath=${NUT_CGIDIR}

PKG_SYSCONFSUBDIR?=	nut
NUT_CONFDIR=		${PKG_SYSCONFDIR}
NUT_EGDIR=		${PREFIX}/share/examples/nut
NUT_STATEDIR=		/var/db/nut
NUT_CGIDIR=		${PREFIX}/share/nut/cgi

CONF_FILES=		${NUT_EGDIR}/hosts.conf.sample ${NUT_CONFDIR}/hosts.conf
CONF_FILES+=		${NUT_EGDIR}/upsset.conf.sample \
			${NUT_CONFDIR}/upsset.conf
CONF_FILES+=		${NUT_EGDIR}/upsstats-single.html.sample \
			${NUT_CONFDIR}/upsstats-single.html
CONF_FILES+=		${NUT_EGDIR}/upsstats.html.sample \
			${NUT_CONFDIR}/upsstats.html

OWN_DIRS=		${NUT_CONFDIR}

.include "../../graphics/gd/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
