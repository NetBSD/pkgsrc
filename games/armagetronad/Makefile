# $NetBSD: Makefile,v 1.5 2020/11/05 09:08:06 ryoon Exp $
#

PKGREVISION= 2
.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}
COMMENT=	Tron clone in 3D with advanced gameplay and multiplayer

MAINTAINER=	pkgsrc-users@NetBSD.org

# Disable server, build client
CONFIGURE_ARGS+=	--disable-dedicated

# pkgsrc specific handling of configuration
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	armagetronad
BUILD_DEFS+=		PKG_SYSCONFBASE
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/examples
MAKE_DIRS+=	${PKG_SYSCONFDIR}/examples/cvs_test

.for f in aiplayers.cfg default.cfg master.srv rc.config settings.cfg settings_authentication.cfg settings_dedicated.cfg settings_visual.cfg subcultures.srv
CONF_FILES+=	${EGDIR}/armagetronad/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.for f in breakfast_in_hell.cfg death_zone.cfg fortress_soccer.cfg single_use_turbo.cfg teamsumo.cfg
CONF_FILES+=	${EGDIR}/armagetronad/examples/${f} ${PKG_SYSCONFDIR}/examples/${f}
.endfor

.for f in fortress_complete.cfg fortress_physics.cfg fortress_politics.cfg fortress_scoring.cfg sumo_complete.cfg
CONF_FILES+=	${EGDIR}/armagetronad/examples/cvs_test/${f} ${PKG_SYSCONFDIR}/examples/cvs_test/${f}
.endfor

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
