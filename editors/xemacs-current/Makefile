# $NetBSD: Makefile,v 1.6 2002/04/05 18:44:01 magick Exp $

DISTNAME=	xemacs-21.5.5
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/xemacs-21.5/ \
                ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/xemacs-21.5/ \
                ftp://ftp.lab.kdd.co.jp/xemacs/xemacs-21.5/

MAINTAINER=	magick@netbsd.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	*BETA* XEmacs text editor version 21.5.5

USE_X11=	YES
USE_BUILDLINK_ONLY=	YES
HAS_CONFIGURE=	YES

PLIST_SUBST+=	EMACSVER=xemacs-21.5-b5
MESSAGE_SUBST+=	EMACSVER=xemacs-21.5-b5

.include "../../mk/bsd.prefs.mk"

XEMACS_WIDGETS?= lucid
.if ${XEMACS_WIDGETS} == gtk
.include "../../x11/gtk/buildlink.mk"
WITH_WIDGETS=	--with-gtk
.elif ${XEMACS_WIDGETS} == gnome
.include "../../x11/gnome-libs/buildlink.mk"
WITH_WIDGETS=	--with-gnome
.elif ${XEMACS_WIDGETS} == motif
.include "../../mk/motif.buildlink.mk"
.else
USE_XAW=	YES
WITH_WIDGETS=	--with-widgets=lucid
.endif

.if defined(XEMACS_ESD) && ${XEMACS_ESD} == YES
.include "../../audio/esound/buildlink.mk"
.endif

.if defined(USE_LDAP) && ${USE_LDAP} == YES
WITH_LDAP=	--with-ldap=yes
.include "../../databases/openldap/buildlink.mk"
.else
WITH_LDAP=	--with-ldap=no
.endif

.if defined(USE_XFACE) && ${USE_XFACE} == YES
.include "../../mail/faces/buildlink.mk"
WITH_XFACE=	--with-xface=yes
.else
WITH_XFACE=	--with-xface=no
.endif

.if defined(EMACS_CANNA) && ${EMACS_CANNA} == YES
WITH_CANNA=	--with-canna=yes
DEPENDS+=	Canna-lib-3*:../../japanese/canna-lib
.else
WITH_CANNA=	--with-canna=no
.endif

.include "../../databases/gdbm/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"

CONFIGURE_ARGS+=	${MACHINE_GNU_PLATFORM} --prefix=${PREFIX} \
			--with-clash-detection --with-mule=yes \
			--with-ncurses=no ${WITH_WIDGETS} \
			${WITH_LDAP} ${WITH_XFACE} \
			${WITH_CANNA} \
			--infopath="${PREFIX}/info:${X11BASE}/info:/usr/local/info" \
			--site-includes=${PREFIX}/include:${WRKDIR} \
			--site-libraries=${PREFIX}/lib \
			--error-checking=none \
			--with-msw=no

CFLAGS+=		-Dunix
MAKE_ENV+=		INSTALL_MAN="${INSTALL_MAN}"

post-patch:
	@${RM} -f ${WRKSRC}/etc/ctags.1.orig

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
