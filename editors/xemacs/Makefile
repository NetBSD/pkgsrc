# $NetBSD: Makefile,v 1.65 2003/12/22 07:08:30 uebayasi Exp $

DISTNAME=	xemacs-21.4.14
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS:=xemacs-21.4/}
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	XEmacs text editor version 21

NOT_FOR_PLATFORM=	*-*-mips*	# fails purespace dumping

USE_BUILDLINK2=	YES
USE_X11=	YES

BUILD_DEFS+=	USE_LDAP USE_XFACE
DIST_SUBDIR=	xemacs
EXTRA_FILES=	${DISTNAME}-elc.tar.gz ${DISTNAME}-info.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
PLIST_SUBST+=	DISTNAME="${DISTNAME}"
MESSAGE_SUBST+=	DISTNAME="${DISTNAME}"

.include "../../mk/bsd.prefs.mk"

# XXX GUI configuration is a mess...
#
#.if defined(USE_ATHENA)
#WITH_DIALOGS= \
#		--with-menubars=athena \
#		--with-scrollbars=athena \
#		--with-dialogs=athena \
#		--with-widgets=athena \
#		--with-athena=xaw \
#		--with-xim=xlib
#.include "../../mk/xaw.buildlink2.mk"
#.elif defined(USE_MOTIF)
#WITH_DIALOGS= \
#		--with-menubars=motif \
#		--with-scrollbars=motif \
#		--with-dialogs=motif \
#		--with-widgets=motif \
#		--with-xim=motif
#.include "../../mk/motif.buildlink2.mk"
#.elif defined(USE_GTK)
#WITH_DIALOGS= \
#		--with-gtk \
#		--with-menubars=yes \
#		--with-scrollbars=yes \
#		--with-dialogs=yes \
#		--with-widgets=yes \
#		--with-xim=yes
#.include "../../x11/gtk/buildlink2.mk"
#.else
# XXX Default is "lucid".  Due to the output of `configure --help', Lucid
#     widgets wrap Athena, so xaw.buildlink2.mk.
WITH_DIALOGS= \
		--with-toolbars=yes \
		--with-menubars=lucid \
		--with-scrollbars=lucid \
		--with-dialogs=lucid \
		--with-widgets=lucid \
		--with-athena=xaw \
		--with-xim=xlib
.include "../../mk/xaw.buildlink2.mk"
#.endif

.if ${OPSYS} == "SunOS"
.  if !exists(/usr/demo/SOUND/libaudio.a) && !exists(/usr/demo/SOUND/lib/libaudio.a)
CONFIGURE_ARGS+=	--with_sound=none
.  endif
.endif

.if defined(USE_LDAP) && (${USE_LDAP} == "YES")
WITH_LDAP=	--with-ldap
.  include "../../databases/openldap/buildlink2.mk"
.else
WITH_LDAP=	--without-ldap
.endif

.if defined(USE_XFACE) && (${USE_XFACE} == "YES")
WITH_XFACE=	--with-xface
.  include "../../mail/faces/buildlink2.mk"
.else
WITH_XFACE=	--without-xface
.endif

.if defined(EMACS_CANNA) && (${EMACS_CANNA} == "YES")
.  include "../../inputmethod/canna-lib/buildlink2.mk"
WITH_CANNA=	--with-canna
.else
WITH_CANNA=	--without-canna
.endif

.include "../../databases/gdbm/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

INFOPATH=	${PREFIX}/info:${X11BASE}/info:/usr/local/info

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-clash-detection
CONFIGURE_ARGS+=	--with-mule=yes
.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--with-ncurses=no
.endif
CONFIGURE_ARGS+=	--with-msw=no
CONFIGURE_ARGS+=	${WITH_DIALOGS} ${WITH_LDAP} ${WITH_XFACE} ${WITH_CANNA}
CONFIGURE_ARGS+=	--infopath="${INFOPATH}"
CONFIGURE_ARGS+=	--site-includes=${BUILDLINK_DIR}/include:${WRKDIR}
CONFIGURE_ARGS+=	--site-libraries=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--site-runtime-libraries=${PREFIX}/lib

CFLAGS+=		-Dunix

.if defined(MANZ)
PLIST_SUBST+=	ELSUFX=.gz
.else
PLIST_SUBST+=	ELSUFX=
.endif

post-extract:
	@for f in ${EXTRA_FILES}; do \
		${GTAR} xzCf ${WRKDIR} ${DISTDIR}/${DIST_SUBDIR}/$$f; \
	done

post-patch:
	@${RM} -f ${WRKSRC}/etc/ctags.1.orig

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/${DISTNAME}
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xemacs
.if defined(MANZ)
	${FIND} ${PREFIX}/lib/${DISTNAME} -name "*.el" -type f | \
	${XARGS} ${GZIP_CMD}
.endif

.include "../../mk/bsd.pkg.mk"
