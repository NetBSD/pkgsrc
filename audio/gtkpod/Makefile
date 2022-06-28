# $NetBSD: Makefile,v 1.86 2022/06/28 11:30:54 wiz Exp $
#

DISTNAME=	gtkpod-1.0.0
PKGREVISION=	45
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkpod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.gtkpod.org/
COMMENT=	GUI for iPod using GTK2
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash:run intltool gmake lex msgfmt perl:run pkg-config

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t
CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t -Du_int64_t=uint64_t

REPLACE_PERL+=		scripts/mab2vcard

REPLACE_BASH=		scripts/*.sh

REPLACE_PYTHON+=	scripts/sync-palm-jppy.py
.include "../../lang/python/application.mk"

DEPENDS+=		bash>=3.2.9:../../shells/bash

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0
BUILDLINK_API_DEPENDS.libgpod+=	libgpod>=0.7.0

.include "../../audio/libgpod/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libgnomecanvasmm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
