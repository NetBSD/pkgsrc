# $NetBSD: Makefile,v 1.9 2003/05/02 11:54:36 wiz Exp $
#

DISTNAME=	libgnomeui-2.2.0.1
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomeui/2.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Core GNOME2 graphical libraries

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_PERL5=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
