# $NetBSD: Makefile,v 1.3 2010/03/20 21:32:40 adrianp Exp $
#

DISTNAME=		ctrlproxy-3.0.8
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
PKG_DESTDIR_SUPPORT=	user-destdir
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
