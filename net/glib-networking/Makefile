# $NetBSD: Makefile,v 1.28 2017/08/29 23:08:39 prlw1 Exp $
#

DISTNAME=	glib-networking-2.50.0
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glib-networking/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Network-related giomodules for glib
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-ca-certificates=/etc/ssl/certs/ca-certificates.crt
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake gettext

# gcc>=4.2 specific -Werror=XXX flags will be added unconditionally.
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.[01].*) || !empty(CC_VERSION:Mgcc-[1-3].*)
CONFIGURE_ARGS+= 	--disable-more-warnings
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=format-nonliteral
CWRAPPERS_APPEND.cc+=	-Wno-error=format-nonliteral
.endif

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.46.0
.include "../../devel/glib2/modules.mk"
BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.3.1
.include "../../www/libproxy/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=		gnutls>=3.0
.include "../../security/gnutls/buildlink3.mk"
# XXX libcgrypt is not necessary if gnutls was built against nettle,
# but the assumption is hardwired at multiple places
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
