# $NetBSD: Makefile,v 1.112 2007/07/03 10:36:15 lkundrak Exp $

DISTNAME=	gaim-1.5.0
PKGREVISION=	6
CATEGORIES=	chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pidgin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://gaim.sourceforge.net/
COMMENT=	GTK+ 2.x based multi-protocol instant messaging client

CONFLICTS+=		gaim-gnome-[0-9]*

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

SHLIBTOOL_OVERRIDE=	# empty

CONFIGURE_ARGS+=	--disable-binreloc
CONFIGURE_ARGS+=	--disable-gevolution
CONFIGURE_ENV+=		DLLIB=${BUILDLINK_LDADD.dl}

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
_INSTALL_UNSTRIPPED=	yes
.endif

.if ${X11_TYPE} != "native"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.elif !exists(${X11BASE}/include/X11/extensions/scrnsaver.h)
CONFIGURE_ARGS+=	--disable-screensaver
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
