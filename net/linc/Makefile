# $NetBSD: Makefile,v 1.18 2003/07/21 17:10:50 martti Exp $
#

DISTNAME=		linc-1.0.1
PKGREVISION=		2
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/linc/1.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Network client/server library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/linc.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
