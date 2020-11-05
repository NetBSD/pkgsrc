# $NetBSD: Makefile,v 1.5 2020/11/05 09:08:07 ryoon Exp $
#

PKGREVISION= 2
.include "../../games/armagetronad/Makefile.common"

PKGNAME=	${DISTNAME:S/.src//:S/armagetronad/armagetronad-server/}
COMMENT=	Server for the armagetronad game

MAINTAINER=	pkgsrc-users@NetBSD.org

# Enable server, don't build client
CONFIGURE_ARGS+=	--enable-dedicated

# pkgsrc specific handling of configuration
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	armagetronad-dedicated
BUILD_DEFS+=		PKG_SYSCONFBASE
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/examples
MAKE_DIRS+=	${PKG_SYSCONFDIR}/examples/cvs_test

.for f in aiplayers.cfg default.cfg master.srv rc.config settings.cfg settings_authentication.cfg settings_dedicated.cfg settings_visual.cfg subcultures.srv
CONF_FILES+=	${EGDIR}/armagetronad-dedicated/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.for f in breakfast_in_hell.cfg death_zone.cfg fortress_soccer.cfg single_use_turbo.cfg teamsumo.cfg
CONF_FILES+=	${EGDIR}/armagetronad-dedicated/examples/${f} ${PKG_SYSCONFDIR}/examples/${f}
.endfor

.for f in fortress_complete.cfg fortress_physics.cfg fortress_politics.cfg fortress_scoring.cfg sumo_complete.cfg
CONF_FILES+=	${EGDIR}/armagetronad-dedicated/examples/cvs_test/${f} ${PKG_SYSCONFDIR}/examples/cvs_test/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
