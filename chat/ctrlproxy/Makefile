# $NetBSD: Makefile,v 1.1.1.1 2009/01/04 01:05:46 adrianp Exp $
#

DISTNAME=		ctrlproxy-3.0.8
CATEGORIES=		chat
MASTER_SITES=		http://www.ctrlproxy.org/releases/

MAINTAINER=		adrianp@NetBSD.org
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

.include "options.mk"

post-install:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE} install
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ctrlproxy/README
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ctrlproxy
	${INSTALL_DATA} ${WRKSRC}/motd \
		${PREFIX}/share/examples/ctrlproxy/motd
	${INSTALL_DATA} ${WRKSRC}/config.default \
		${PREFIX}/share/examples/ctrlproxy/config.default
	${INSTALL_DATA} ${WRKSRC}/config.example \
		${PREFIX}/share/examples/ctrlproxy/config.example

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
