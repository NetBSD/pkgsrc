# $NetBSD: Makefile,v 1.1.1.1 2003/01/13 21:22:43 magick Exp $

DISTNAME=	xemacs-21.1.14
PKGNAME=	xemacs-nox-21.1.14
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/xemacs-21.1/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/xemacs-21.1/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/xemacs-21.1/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/xemacs-21.1/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/xemacs-21.1/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	magick@netbsd.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	XEmacs text editor version 21

NOT_FOR_PLATFORM=	*-*-mips*	# fails purespace dumping

CONFLICTS=	xemacs-[0-9]*

PLIST_SRC=	${.CURDIR}/../xemacs/
DISTINFO_FILE=	${.CURDIR}/../xemacs/distinfo
PATCHDIR=	${.CURDIR}/../xemacs/patches

USE_BUILDLINK2=	YES
#USE_X11=	YES

BUILD_DEFS+=	USE_LDAP USE_XFACE
DIST_SUBDIR=	xemacs
EXTRA_FILES=	${DISTNAME}-elc.tar.gz ${DISTNAME}-info.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
PLIST_SUBST+=	DISTNAME="${DISTNAME}"
MESSAGE_SUBST+=	DISTNAME="${DISTNAME}"

.include "../../mk/bsd.prefs.mk"

.if defined(MANZ)
PLIST_SUBST+=	ELSUFX='.gz'
.else
PLIST_SUBST+=	ELSUFX=''
.endif

#.if defined(USE_ATHENA)
# WITH_DIALOGS=  --with-menubars=athena\
#		--with-scrollbars=athena\
#		--with-dialogs=athena\
#		--with-xim=xlib
#.else
# WITH_DIALOGS=  --with-dialogs=motif
#.endif

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
#.include "../../graphics/jpeg/buildlink2.mk"
#.include "../../graphics/png/buildlink2.mk"
#.include "../../graphics/tiff/buildlink2.mk"
#.include "../../graphics/xpm/buildlink2.mk"
#.if !defined(USE_ATHENA)
#.include "../../mk/motif.buildlink2.mk"
#.endif
.include "../../mk/ossaudio.buildlink2.mk"

INFOPATH=	${PREFIX}/info:${X11BASE}/info:/usr/local/info

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-clash-detection
CONFIGURE_ARGS+=	--with-mule=yes
CONFIGURE_ARGS+=	--without-ncurses
CONFIGURE_ARGS+=	--without-msw
CONFIGURE_ARGS+=	--with-session=yes
CONFIGURE_ARGS+=	${WITH_DIALOGS} ${WITH_LDAP} ${WITH_XFACE} ${WITH_CANNA}
CONFIGURE_ARGS+=	--infopath="${INFOPATH}"
CONFIGURE_ARGS+=	--lockdir=/var/tmp/xemacs.lock
CONFIGURE_ARGS+=	--site-includes=${PREFIX}/include:${WRKDIR}
CONFIGURE_ARGS+=	--site-libraries=${PREFIX}/lib
CONFIGURE_ARGS+=	--without-x11	# XXX -nox
CONFIGURE_ARGS+=	--without-jpeg	# XXX -nox
CONFIGURE_ARGS+=	--without-png	# XXX -nox
CONFIGURE_ARGS+=	--without-tiff	# XXX -nox
CONFIGURE_ARGS+=	--without-xpm	# XXX -nox

CFLAGS+=		-Dunix
MAKE_ENV+=		INSTALL_MAN="${INSTALL_MAN}"
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-extract:
	for FILE in ${EXTRA_FILES}; do					\
		${GTAR} xzCf ${WRKDIR} ${DISTDIR}/${DIST_SUBDIR}/$$FILE; \
	done

post-patch:
	@${RM} -f ${WRKSRC}/etc/ctags.1.orig

post-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/${DISTNAME}
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/xemacs
	@if [ "X${MANZ}" != X"" ]; then \
		${WRKSRC}/lib-src/gzip-el.sh ${PREFIX}/lib/${DISTNAME}; \
	fi

.include "../../mk/bsd.pkg.mk"
