# $NetBSD: Makefile,v 1.35 2003/07/13 13:50:46 wiz Exp $
#

DISTNAME=	gaim-0.64
PKGREVISION=	3
CATEGORIES=	chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gaim/}

PATCH_SITES=		http://www.chipx86.com/
PATCHFILES=		${DISTNAME}-msncrashes-20030705-0044.diff
PATCH_DIST_STRIP=	-p0

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://gaim.sourceforge.net/
COMMENT=	GTK2 based client for the AOL Instant Messenger chat system

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

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/scrnsaver.h)
CONFIGURE_ARGS+=	--disable-screensaver
.endif

.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/gtkspell/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
