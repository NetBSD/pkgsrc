# $NetBSD: Makefile,v 1.54 2006/09/04 09:20:51 martin Exp $

DISTNAME=	xemacs-21.5.27

CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS:=xemacs-21.5/}

MAINTAINER=	magick@NetBSD.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	*BETA* XEmacs text editor version 21.5.19

CONFLICTS+=	gnuclient-[0-9]*


BUILD_DEFS+=	XEMACS_WIDGETS
PLIST_SUBST+=	EMACSVER=xemacs-21.5-b19
MESSAGE_SUBST+=	EMACSVER=xemacs-21.5-b19

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

INFOPATH=	${PREFIX}/${PKGINFODIR}:${X11BASE}/${PKGINFODIR}:${LOCALBASE}/${PKGINFODIR}

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-clash-detection
CONFIGURE_ARGS+=	--with-mule=yes
CONFIGURE_ARGS+=	--without-ncurses
CONFIGURE_ARGS+=	--without-msw
CONFIGURE_ARGS+=	${WITH_WIDGETS}
CONFIGURE_ARGS+=	--with-infopath=${INFOPATH:Q}
CONFIGURE_ARGS+=	--with-site-includes=${PREFIX}/include:${WRKDIR}
CONFIGURE_ARGS+=	--with-site-libraries=${PREFIX}/lib

CFLAGS+=		-Dunix
# newer gcc has big trouble with aliasing otherwise - this should be fixed
# in the source, but untill then, use the big hammer here:
CFLAGS+=		-fno-strict-aliasing

INFO_FILES=		# PLIST

post-patch:
	@${RM} -f ${WRKSRC}/etc/ctags.1.orig

.include "../../mk/bsd.pkg.mk"
