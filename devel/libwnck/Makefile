# $NetBSD: Makefile,v 1.20 2004/09/03 13:06:25 jmmv Exp $
#

DISTNAME=	libwnck-2.6.2.1
CATEGORIES=	devel x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libwnck/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Library to write pagers and tasklists

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libwnck-1.0.pc.in

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
