# $NetBSD: Makefile,v 1.7 2003/05/02 11:54:38 wiz Exp $
#

DISTNAME=	libwnck-2.2.1
PKGREVISION=	1
CATEGORIES=	devel x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libwnck/2.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Library to write pagers and tasklists

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libwnck-1.0.pc.in

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
