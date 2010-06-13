# $NetBSD: Makefile,v 1.51 2010/06/13 22:45:25 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/ups-nut/Makefile.common"

PKGNAME=		${DISTNAME:S/nut/ups-nut-cgi/}
PKGREVISION=		3
COMMENT=		Network UPS Tools CGI scripts

DEPENDS+=		ups-nut-2.*:../../sysutils/ups-nut

BUILD_TARGET=		cgi
INSTALL_TARGET=		install-cgi
INSTALLATION_DIRS+=	${NUT_EGDIR}

CONFIGURE_ARGS+=	--with-cgi
CONFIGURE_ARGS+=	--with-cgipath=${NUT_CGIDIR:Q}

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
.include "../../mk/bsd.pkg.mk"
