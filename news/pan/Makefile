# $NetBSD: Makefile,v 1.71.2.1 2012/10/03 12:09:11 spz Exp $
#

DISTNAME=		pan-0.139
PKGREVISION=		3
CATEGORIES=		news
MASTER_SITES=		http://pan.rebelbase.com/download/releases/${DISTNAME:C/pan-//}/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK2
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} != "Darwin" && ${OPSYS} != "SunOS" && ${OPSYS} != "Linux")
LIBS+=			-lcompat
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mail/gmime24/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.16.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
