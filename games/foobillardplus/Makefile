# $NetBSD: Makefile,v 1.4 2020/03/20 11:57:41 nia Exp $

DISTNAME=	foobillardplus-3.42beta
PKGNAME=	${DISTNAME:S/beta/b/}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=foobillardplus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://foobillardplus.sourceforge.net/
COMMENT=	Free OpenGL-billard game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoconf autoreconf

CONFIGURE_ARGS+=	--enable-standard
CONFIGURE_ARGS+=	--disable-fastmath

LDFLAGS.SunOS+=		-lsocket -lnsl

SUBST_CLASSES+=			fix-datadir
SUBST_STAGE.fix-datadir=	pre-configure
SUBST_MESSAGE.fix-datadir=	fixing datadir
SUBST_FILES.fix-datadir=	src/sys_stuff.c
SUBST_SED.fix-datadir=		-e 's,@DATADIR@,${PREFIX}/share/foobillardplus/data,g'

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
