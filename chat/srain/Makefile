# $NetBSD: Makefile,v 1.1 2020/03/30 09:11:53 nia Exp $

DISTNAME=	srain-1.0.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=SrainApp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://srain.im/
COMMENT=	Modern IRC client written in GTK
LICENSE=	gnu-gpl-v3

HAS_CONFIGURE=	yes

USE_TOOLS+=	pkg-config gmake
USE_TOOLS+=	msgfmt msgmerge xgettext

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-debug

BUILD_TARGET=	default

MAKE_FLAGS+=	MAKE=${GMAKE:Q}
MAKE_FLAGS+=	INSTALL=${INSTALL:Q}

AUTO_MKDIRS=	yes

OWN_DIRS+=	${PKG_SYSCONFDIR}/srain

CONF_FILES+=	share/examples/srain/builtin.cfg \
		${PKG_SYSCONFDIR}/srain/builtin.cfg

# XXX xgettext: unknown option -- package-name=Srain
_TOOLS_USE_PKGSRC.xgettext=	yes

.include "../../devel/libconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
