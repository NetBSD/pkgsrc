# $NetBSD: Makefile,v 1.43 2006/08/02 12:30:22 ghen Exp $

DISTNAME=		nut-2.0.3
PKGNAME=		ups-nut-cgi-2.0.3
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://random.networkupstools.org/source/2.0/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.networkupstools.org/
COMMENT=		Network UPS Tools CGI scripts

DISTINFO_FILE=		${.CURDIR}/../../sysutils/ups-nut/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/ups-nut/patches

DEPENDS+=		ups-nut-2.*:../../sysutils/ups-nut

BUILD_TARGET=		cgi
INSTALL_TARGET=		install-cgi

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${NUT_CONFDIR:Q}			\
			--datadir=${NUT_DATADIR:Q}			\
			--localstatedir=${NUT_STATEDIR:Q}		\
			--with-statepath=${NUT_STATEDIR:Q}		\
			--with-cgi					\
			--with-cgipath=${NUT_CGIDIR:Q}

PKG_SYSCONFSUBDIR?=	nut
NUT_CONFDIR=		${PKG_SYSCONFDIR}
NUT_DATADIR=		${PREFIX}/share/nut
NUT_EGDIR=		${PREFIX}/share/examples/nut
NUT_STATEDIR?=		${VARBASE}/db/nut
NUT_CGIDIR=		${PREFIX}/libexec/cgi-bin

BUILD_DEFS+=		NUT_STATEDIR

CONF_FILES=		${NUT_EGDIR}/hosts.conf.sample ${NUT_CONFDIR}/hosts.conf
CONF_FILES+=		${NUT_EGDIR}/upsset.conf.sample		 \
			${NUT_CONFDIR}/upsset.conf
CONF_FILES+=		${NUT_EGDIR}/upsstats-single.html.sample \
			${NUT_CONFDIR}/upsstats-single.html
CONF_FILES+=		${NUT_EGDIR}/upsstats.html.sample \
			${NUT_CONFDIR}/upsstats.html

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
