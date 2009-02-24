# $NetBSD: Makefile,v 1.54 2009/02/24 12:24:48 wiz Exp $
#

DISTNAME=		pan-0.133
CATEGORIES=		news
MASTER_SITES=		http://pan.rebelbase.com/download/releases/${DISTNAME:C/pan-//}/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake msgfmt perl pkg-config
USE_DIRS+=		gnome2-1.5
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} != "Darwin" && ${OPSYS} != "SunOS" && ${OPSYS} != "Linux")
LIBS+=			-lcompat
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
