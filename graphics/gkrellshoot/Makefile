# $NetBSD: Makefile,v 1.5 2026/01/27 08:39:40 wiz Exp $

DISTNAME=	gkrellshoot-0.4.4
PKGREVISION=	3
CATEGORIES=	graphics sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gkrellshoot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GKrellM plugin to take screenshots
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:S/shoot/Shoot/}

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	xscreensaver-[0-9]*:../../x11/xscreensaver

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_FLAGS+=	INSTALL_LIB_DIR=${INSTALL_LIB_DIR:Q}
MAKE_FLAGS+=	INSTALL_LIB=${INSTALL_LIB:Q}
MAKE_FLAGS+=	PLUGIN_DIR=${PREFIX:Q}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
