# $NetBSD: Makefile,v 1.47 2020/03/20 11:58:22 nia Exp $
#

DISTNAME=	pcmanfm-1.3.1
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://pcmanfm.sourceforge.net/
COMMENT=	Extremly fast and lightweight file manager
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt pkg-config

CONF=			share/examples/pcmanfm
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/${CONF}

LIBS.SunOS+=		-lsocket -lnsl

PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/pcmanfm/default
CONF_FILES+=		${CONF}/xdg/pcmanfm/default/pcmanfm.conf \
			${PKG_SYSCONFDIR}/pcmanfm/default/pcmanfm.conf

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../sysutils/libfm/buildlink3.mk"
.include "../../sysutils/libfm-extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
