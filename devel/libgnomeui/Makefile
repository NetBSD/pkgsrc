# $NetBSD: Makefile,v 1.4 2002/11/30 23:21:37 salo Exp $
#

DISTNAME=	libgnomeui-2.0.5
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomeui/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Core GNOME2 graphical libraries

BUILD_DEPENDS+=		gtk-doc>=0.6:../../textproc/gtk-doc
BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_GNU_GETTEXT=	yes
USE_PERL5=		yes
USE_X11=		yes

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
