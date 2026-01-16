# $NetBSD: Makefile,v 1.65 2026/01/16 06:51:22 wiz Exp $

DISTNAME=	pcmanfm-1.3.2
PKGREVISION=	14
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/pcmanfm/
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
