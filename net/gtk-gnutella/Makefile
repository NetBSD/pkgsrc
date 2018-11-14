# $NetBSD: Makefile,v 1.100 2018/11/14 22:22:11 kleink Exp $

DISTNAME=	gtk-gnutella-1.1.11
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-gnutella/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtk-gnutella.sourceforge.net/
COMMENT=	GTK-based gnutella client
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./build.sh
CONFIGURE_ARGS+=	--configure-only
CONFIGURE_ARGS+=	--prefix=${DESTDIR}/${PREFIX}
CONFIGURE_ARGS+=	--localedir="${PREFIX}/${PKGLOCALEDIR}/locale"
CONFIGURE_ARGS+=	--cc=${CC:Q}
CONFIGURE_ARGS+=	--cflags=${CFLAGS:Unone:Q}
CONFIGURE_ARGS+=	--yacc="yacc"

LDFLAGS.SunOS+=	-lsocket -lnsl -liconv

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
