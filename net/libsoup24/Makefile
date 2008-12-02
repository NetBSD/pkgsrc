# $NetBSD: Makefile,v 1.6 2008/12/02 17:13:19 wiz Exp $

DISTNAME=	libsoup-2.24.2.1
PKGNAME=	${DISTNAME:S/libsoup/libsoup24/}
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsoup/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	HTTP library implementation in C

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libsoup.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
