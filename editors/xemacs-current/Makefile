# $NetBSD: Makefile,v 1.44 2005/01/22 13:03:06 magick Exp $

DISTNAME=	xemacs-21.5.18
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS:=xemacs-21.5/}

MAINTAINER=	magick@NetBSD.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	*BETA* XEmacs text editor version 21.5.18

USE_BUILDLINK3=	YES
USE_X11=	YES

BUILD_DEFS+=	XEMACS_WIDGETS
PLIST_SUBST+=	EMACSVER=xemacs-21.5-b18
MESSAGE_SUBST+=	EMACSVER=xemacs-21.5-b18

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

.include "options.mk"

XEMACS_WIDGETS?=	lucid
.if ${XEMACS_WIDGETS} == "gtk"
.  include "../../x11/gtk/buildlink3.mk"
WITH_WIDGETS=	--with-gtk
.elif ${XEMACS_WIDGETS} == "gnome"
.  include "../../x11/gnome-libs/buildlink3.mk"
WITH_WIDGETS=	--with-gnome
.elif ${XEMACS_WIDGETS} == "motif"
.  include "../../mk/motif.buildlink3.mk"
.else
.  include "../../mk/xaw.buildlink3.mk"
WITH_WIDGETS=	--with-widgets=lucid
.endif

.include "../../databases/gdbm/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

INFOPATH=	${PREFIX}/info:${X11BASE}/info:/usr/local/info

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-clash-detection
CONFIGURE_ARGS+=	--error-checking=none
CONFIGURE_ARGS+=	--with-mule=yes
CONFIGURE_ARGS+=	--without-ncurses
CONFIGURE_ARGS+=	--without-msw
CONFIGURE_ARGS+=	${WITH_WIDGETS}
CONFIGURE_ARGS+=	--infopath="${INFOPATH}"
CONFIGURE_ARGS+=	--site-includes=${PREFIX}/include:${WRKDIR}
CONFIGURE_ARGS+=	--site-libraries=${PREFIX}/lib

CFLAGS+=		-Dunix

post-patch:
	@${RM} -f ${WRKSRC}/etc/ctags.1.orig

.include "../../mk/bsd.pkg.mk"
