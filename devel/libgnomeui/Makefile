# $NetBSD: Makefile,v 1.25 2004/02/14 17:21:38 jlam Exp $
#

DISTNAME=	libgnomeui-2.4.0.1
PKGREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomeui/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Core GNOME2 graphical libraries

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_PERL5=		yes
USE_X11=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

PKGCONFIG_BASE=		${WRKSRC}/libgnomeui/libgnomeui-2.0.pc
PKGCONFIG_OVERRIDE=	${PKGCONFIG_BASE}.in

# Needed because part of the pc files doesn't get filled in till after 
# configure does its pass

post-configure:
	${SED} ${PKGCONFIG_OVERRIDE_SED} < ${PKGCONFIG_BASE} > \
		${PKGCONFIG_BASE}.tmp
	${MV} ${PKGCONFIG_BASE}.tmp ${PKGCONFIG_BASE}

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
