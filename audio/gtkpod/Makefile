# $NetBSD: Makefile,v 1.17 2007/08/07 00:06:32 smb Exp $
#

DISTNAME=	gtkpod-0.99.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkpod/}
PKGREVISION=	1

PATCHFILES=	gtkpod-0.99.8_libgpod-0.4.2.diff
PATCH_SITES=	http://ftp.osuosl.org/pub/gentoo/distfiles/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://www.gtkpod.org/
COMMENT=	GUI for iPod using GTK2

GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt perl:run pkg-config

REPLACE_PERL+=		scripts/mab2vcard

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash=	scripts/sync-knotes.sh

REPLACE_PYTHON+=	scripts/sync-palm-jppy.py
.include "../../lang/python/application.mk"

DEPENDS+=		bash>=3.2.9:../../shells/bash

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.4.0
BUILDLINK_API_DEPENDS.libgpod+=	libgpod>=0.4.2

.include "options.mk"

.include "../../audio/libgpod/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
