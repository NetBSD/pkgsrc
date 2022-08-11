# $NetBSD: Makefile,v 1.125 2022/08/11 05:09:11 gutteridge Exp $

PKGNAME=		pan-0.151
PKGREVISION=		1
CATEGORIES=		news
TAG=			${PKGNAME_NOREV:S/pan-/v/} # e.g. v0.151
MASTER_SITES=		https://gitlab.gnome.org/GNOME/pan/-/archive/${TAG}/
EXTRACT_SUFX=		.tar.bz2
DISTNAME=		pan-${TAG}

MAINTAINER=		rhialto@NetBSD.org
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK3
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools
TOOL_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

USE_TOOLS+=		gmake msgfmt perl pkg-config itstool
USE_TOOLS+=		autoconf automake
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gtk3
CONFIGURE_ARGS+=	--with-gnutls
CONFIGURE_ARGS+=	--with-gtkspell

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} != "Darwin" && ${OPSYS} != "SunOS" && ${OPSYS} != "Linux")
LIBS+=			-lcompat
.endif

LIBS.SunOS+=	-lsocket

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

# "Build" these files out of thin air, since base msgfmt doesn't know
# about --xml --desktop.
pre-build:
	${CP} ${FILESDIR}/pan.desktop ${WRKSRC}/org.gnome.pan.desktop
	${CP} ${FILESDIR}/org.gnome.pan.metainfo.xml ${WRKSRC}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/gmime3/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gtkspell3/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
