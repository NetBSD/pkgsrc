# $NetBSD: Makefile,v 1.9 2004/02/14 17:21:50 jlam Exp $
#

DISTNAME=	gpdf-0.112
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gpdf/0.112/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME 2 version of xpdf

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
