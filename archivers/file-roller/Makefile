# $NetBSD: Makefile,v 1.10 2003/12/13 00:45:21 wiz Exp $
#

DISTNAME=	file-roller-2.2.4
PKGREVISION=	3
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/file-roller/2.2/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://fileroller.sourceforge.net/
COMMENT=	Front-end to archiving programs like tar and zip

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		file-roller.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
