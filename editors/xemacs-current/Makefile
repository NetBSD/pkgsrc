# $NetBSD: Makefile,v 1.37 2004/04/04 16:12:01 magick Exp $

DISTNAME=	xemacs-21.5.17
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS:=xemacs-21.5/}

MAINTAINER=	magick@NetBSD.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	*BETA* XEmacs text editor version 21.5.17

USE_BUILDLINK2=	YES
USE_X11=	YES

BUILD_DEFS+=	XEMACS_WIDGETS XEMACS_ESD USE_LDAP USE_XFACE XEMACS_USE_CANNA
PLIST_SUBST+=	EMACSVER=xemacs-21.5-b17
MESSAGE_SUBST+=	EMACSVER=xemacs-21.5-b17

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

.include "../../mk/bsd.prefs.mk"

XEMACS_WIDGETS?=	lucid
.if ${XEMACS_WIDGETS} == "gtk"
.  include "../../x11/gtk/buildlink2.mk"
WITH_WIDGETS=	--with-gtk
.elif ${XEMACS_WIDGETS} == "gnome"
.  include "../../x11/gnome-libs/buildlink2.mk"
WITH_WIDGETS=	--with-gnome
.elif ${XEMACS_WIDGETS} == "motif"
.  include "../../mk/motif.buildlink2.mk"
.else
.  include "../../mk/xaw.buildlink2.mk"
WITH_WIDGETS=	--with-widgets=lucid
.endif

.if defined(XEMACS_ESD) && (${XEMACS_ESD} == "YES")
.  include "../../audio/esound/buildlink2.mk"
.else
CONFIGURE_ARGS += --with-sound=none
.endif

.if defined(USE_LDAP) && (${USE_LDAP} == "YES")
WITH_LDAP=	--with-ldap
.  include "../../databases/openldap/buildlink2.mk"
.else
WITH_LDAP=	--without-ldap
.endif

.if defined(USE_XFACE) && (${USE_XFACE} == "YES")
.  include "../../mail/faces/buildlink2.mk"
WITH_XFACE=	--with-xface
.else
WITH_XFACE=	--without-xface
.endif

.if defined(XEMACS_USE_CANNA) && (${XEMACS_USE_CANNA} == "YES")
.  include "../../inputmethod/canna-lib/buildlink2.mk"
WITH_CANNA=	--with-canna
.else
WITH_CANNA=	--without-canna
.endif

.include "../../databases/gdbm/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

INFOPATH=	${PREFIX}/info:${X11BASE}/info:/usr/local/info

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-clash-detection
CONFIGURE_ARGS+=	--error-checking=none
CONFIGURE_ARGS+=	--with-mule=yes
CONFIGURE_ARGS+=	--without-ncurses
CONFIGURE_ARGS+=	--without-msw
CONFIGURE_ARGS+=	${WITH_WIDGETS} ${WITH_LDAP} ${WITH_XFACE} ${WITH_CANNA}
CONFIGURE_ARGS+=	--infopath="${INFOPATH}"
CONFIGURE_ARGS+=	--site-includes=${PREFIX}/include:${WRKDIR}
CONFIGURE_ARGS+=	--site-libraries=${PREFIX}/lib

CFLAGS+=		-Dunix

post-patch:
	@${RM} -f ${WRKSRC}/etc/ctags.1.orig

.include "../../mk/bsd.pkg.mk"
