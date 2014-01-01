# $NetBSD: Makefile,v 1.22 2014/01/01 11:52:28 wiz Exp $
#

DISTNAME=	glib-networking-2.36.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glib-networking/2.36/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Network-related giomodules for glib
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-ca-certificates=/etc/ssl/certs/ca-certificates.crt
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config gmake gettext

# gcc>=4.2 specific -Werror=XXX flags will be added unconditionally.
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.[01].*) || !empty(CC_VERSION:Mgcc-[1-3].*)
CONFIGURE_ARGS+= 	--disable-more-warnings
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=format-nonliteral
.endif

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.32.1
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/modules.mk"
BUILDLINK_API_DEPENDS.libproxy+= libproxy>=0.3.1
.include "../../www/libproxy/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
# XXX libcgrypt is not necessary if gnutls was built against nettle,
# but the assumption is hardwired at multiple places
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
