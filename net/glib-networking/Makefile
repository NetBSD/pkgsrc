# $NetBSD: Makefile,v 1.7 2011/07/31 11:39:13 gls Exp $
#

DISTNAME=	glib-networking-2.28.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glib-networking/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Network-related giomodules for glib
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-ca-certificates=/etc/ssl/certs/ca-certificates.crt
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config gmake gettext

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.28.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/modules.mk"
BUILDLINK_API_DEPENDS.libproxy+= libproxy>=0.3.1
.include "../../www/libproxy/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
# XXX libcgrypt is not necessary if gnutls was built against nettle,
# but the assumption is hardwired at multiple places
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
