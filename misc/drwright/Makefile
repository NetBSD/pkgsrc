# $NetBSD: Makefile,v 1.1.1.1 2004/02/24 17:05:33 jmmv Exp $
#

DISTNAME=		drwright-0.17
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/drwright/0.17/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.imendio.com/projects/drwright/
COMMENT=		Computer break reminder

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.4:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PERL5=		yes
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		drwright.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
