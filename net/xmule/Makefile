# $NetBSD: Makefile,v 1.10 2003/12/03 13:04:30 jmmv Exp $
#

DISTNAME=	xmule-1.7.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmule/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.xmule.org/
COMMENT=	eDonkey2000 client based on eMule

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		wget>=1.8.2:../../net/wget

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-timedata
CONFIGURE_ARGS+=	--enable-gui
CONFIGURE_ARGS+=	--enable-protocol
CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--enable-ftp
CONFIGURE_ARGS+=	--enable-resources
CONFIGURE_ARGS+=	--enable-prologio
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--enable-final
CONFIGURE_ARGS+=	--enable-timer
CONFIGURE_ARGS+=	--with-gtk
CONFIGURE_ARGS+=	--disable-profile
CONFIGURE_ARGS+=	--without-included-gettext

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
