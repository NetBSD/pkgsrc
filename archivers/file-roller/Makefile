# $NetBSD: Makefile,v 1.32 2004/10/03 00:13:04 tv Exp $
#

DISTNAME=	file-roller-2.8.0
PKGREVISION=	1
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/file-roller/2.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fileroller.sourceforge.net/
COMMENT=	Front-end to archiving programs like tar and zip

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gtar-base>=1.13.25:../../archivers/gtar-base
DEPENDS+=		unzip>=5.50nb2:../../archivers/unzip
DEPENDS+=		zip>=2.3nb2:../../archivers/zip

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		file-roller.schemas

EVAL_PREFIX+=		PREFIX.gtar=gtar
PREFIX.gtar_DEFAULT=	${LOCALBASE}
CPPFLAGS+=		-DFILEROLLER_TAR=\"\\\"${PREFIX.gtar}/bin/${GNU_PROGRAM_PREFIX}tar\\\"\"

EVAL_PREFIX+=		PREFIX.unzip=unzip
PREFIX.unzip_DEFAULT=	${LOCALBASE}
CPPFLAGS+=		-DFILEROLLER_UNZIP=\"\\\"${PREFIX.unzip}/bin/unzip\\\"\"

EVAL_PREFIX+=		PREFIX.zip=zip
PREFIX.zip_DEFAULT=	${LOCALBASE}
CPPFLAGS+=		-DFILEROLLER_ZIP=\"\\\"${PREFIX.zip}/bin/zip\\\"\"

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
