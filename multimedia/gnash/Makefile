# $NetBSD: Makefile,v 1.62 2012/12/16 01:52:26 obache Exp $
#

DISTNAME=		gnash-0.8.10
PKGREVISION=		12
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_GNU:=gnash/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnashdev.org/
COMMENT=		GPL SWF player
LICENSE=		gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		bash gmake msgfmt pkg-config
INSTALL_TARGET=		install install-plugin

# /bin/sh finds a syntax error without line number
CONFIG_SHELL=		${TOOLS_BASH}
CONFIGURE_ARGS+=	--with-boost-incl=${BUILDLINK_PREFIX.boost-headers}/include
CONFIGURE_ARGS+=	--with-boost-lib=${BUILDLINK_PREFIX.boost-libs}/lib
CONFIGURE_ARGS+=	--without-gconf
CONFIGURE_ARGS+=	--with-x11-incl=${X11BASE}/include
CONFIGURE_ARGS+=	--with-x11-lib=${X11BASE}/lib

EGDIR=			${PREFIX}/share/examples/gnash
INSTALLATION_DIRS=	${EGDIR}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
CONF_FILES+=		${EGDIR}/gnashpluginrc ${PKG_SYSCONFDIR}/gnashpluginrc
CONF_FILES+=		${EGDIR}/gnashrc ${PKG_SYSCONFDIR}/gnashrc

.include "options.mk"

#ld: .libs/libgnashplugin_la-plugin.o(.text+0x5564): unresolvable relocation
# against symbol `_ZNKSs5c_strEv'
BUILDLINK_TRANSFORM+=	rm:-fvisibility-inlines-hidden

.include "../../audio/speex/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
