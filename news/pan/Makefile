# $NetBSD: Makefile,v 1.103 2019/10/15 18:09:21 rhialto Exp $

DISTNAME=		pan-0.146
CATEGORIES=		news
MASTER_SITES=		http://pan.rebelbase.com/download/releases/${DISTNAME:C/pan-//}/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rhialto@NetBSD.org
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK2
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

USE_TOOLS+=		gmake msgfmt perl pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gnutls

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} != "Darwin" && ${OPSYS} != "SunOS" && ${OPSYS} != "Linux")
LIBS+=			-lcompat
.endif

LIBS.SunOS+=	-lsocket -liconv

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
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.16.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
