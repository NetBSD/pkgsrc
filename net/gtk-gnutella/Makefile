# $NetBSD: Makefile,v 1.129 2024/05/16 06:15:19 wiz Exp $

DISTNAME=	gtk-gnutella-1.2.2
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-gnutella/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtk-gnutella.sourceforge.net/
COMMENT=	GTK-based gnutella client
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./build.sh
CONFIGURE_ARGS+=	--configure-only
# causes segfaults because the malloc() is used by other libraries as well
# before it is set up completely, see discussion in
# https://github.com/gtk-gnutella/gtk-gnutella/pull/37
CONFIGURE_ARGS+=	--disable-malloc
CONFIGURE_ARGS+=	--prefix=${DESTDIR}/${PREFIX}
CONFIGURE_ARGS+=	--localedir="${PREFIX}/${PKGLOCALEDIR}/locale"
CONFIGURE_ARGS+=	--cc=${CC:Q}
CONFIGURE_ARGS+=	--cflags=${CFLAGS:Unone:Q}
CONFIGURE_ARGS+=	--yacc="yacc"

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
