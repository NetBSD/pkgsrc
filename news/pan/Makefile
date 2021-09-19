# $NetBSD: Makefile,v 1.113 2021/09/19 17:40:27 rhialto Exp $

PKGNAME=		pan-0.147
CATEGORIES=		news
TAG=			${PKGNAME_NOREV:tu:C/-/_/:C/\./_/} # PAN_0_147
MASTER_SITES=		https://gitlab.gnome.org/GNOME/pan/-/archive/${TAG}/
EXTRACT_SUFX=		.tar.bz2
DISTNAME=		pan-${TAG}

MAINTAINER=		rhialto@NetBSD.org
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK2
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake msgfmt perl pkg-config itstool
USE_TOOLS+=		autoconf automake
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gnutls

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} != "Darwin" && ${OPSYS} != "SunOS" && ${OPSYS} != "Linux")
LIBS+=			-lcompat
.endif

LIBS.SunOS+=	-lsocket -liconv

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

# "Build" these files out of thin air, since base msgfmt doesn't know
# about --xml --desktop.
pre-build:
	${CP} ${FILESDIR}/pan.appdata.xml ${WRKSRC}/
	${CP} ${FILESDIR}/pan.desktop ${WRKSRC}/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
