# $NetBSD: Makefile,v 1.45 2003/12/13 00:45:21 wiz Exp $
#

DISTNAME=	gaim-0.74
PKGREVISION=	2
CATEGORIES=	chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gaim/}
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/marcus/
PATCHFILES=	${DISTNAME}-openssl.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://gaim.sourceforge.net/
COMMENT=	GTK2 based client for the AOL Instant Messenger chat system

BUILD_USES_MSGFMT=	YES
DEPENDS+=	gnome2-dirs>=1.1:../../misc/gnome2-dirs

CONFLICTS+=	gaim-gnome-[0-9]*

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--disable-nas
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-nss
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--disable-gnutls

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/scrnsaver.h)
CONFIGURE_ARGS+=	--disable-screensaver
.endif

.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/gtkspell/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
