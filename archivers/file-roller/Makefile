# $NetBSD: Makefile,v 1.20 2004/02/10 11:52:05 jmmv Exp $
#

DISTNAME=	file-roller-2.4.4
PKGREVISION=	2
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/file-roller/2.4/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://fileroller.sourceforge.net/
COMMENT=	Front-end to archiving programs like tar and zip

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		gtar-base>=1.13.25:../../archivers/gtar-base
DEPENDS+=		unzip>=5.50nb2:../../archivers/unzip
DEPENDS+=		zip>=2.3nb2:../../archivers/zip

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
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
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
