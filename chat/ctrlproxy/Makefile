# $NetBSD: Makefile,v 1.8 2012/10/03 00:02:34 asau Exp $
#

DISTNAME=		ctrlproxy-3.0.8
PKGREVISION=		4
CATEGORIES=		chat
MASTER_SITES=		http://www.ctrlproxy.org/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ctrlproxy.org/
COMMENT=		Detachable internet relay chat proxy server

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
PKG_SYSCONFSUBDIR=	ctrlproxy

CONF_FILES=		${PREFIX}/share/examples/ctrlproxy/motd \
			${PKG_SYSCONFDIR}/motd
CONF_FILES+=		${PREFIX}/share/examples/ctrlproxy/config.default \
			${PKG_SYSCONFDIR}/config

PKGCONFIG_OVERRIDE+=	ctrlproxy.pc.in
INSTALLATION_DIRS+=	share/examples/ctrlproxy

.include "options.mk"

post-install:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} DESTDIR=${DESTDIR:Q} ${MAKE} install
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ctrlproxy/README
	${INSTALL_DATA} ${WRKSRC}/motd \
		${DESTDIR}${PREFIX}/share/examples/ctrlproxy/motd
	${INSTALL_DATA} ${WRKSRC}/config.default \
		${DESTDIR}${PREFIX}/share/examples/ctrlproxy/config.default
	${INSTALL_DATA} ${WRKSRC}/config.example \
		${DESTDIR}${PREFIX}/share/examples/ctrlproxy/config.example

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
