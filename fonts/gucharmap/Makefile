# $NetBSD: Makefile,v 1.2 2003/12/14 16:41:52 taca Exp $
#

DISTNAME=	gucharmap-1.2.0
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gucharmap/1.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gucharmap.sourceforge.net/
COMMENT=	Unicode/ISO10646 character map and font viewer

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/gucharmap.pc.in

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
