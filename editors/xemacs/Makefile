# $NetBSD: Makefile,v 1.37 2001/12/02 14:42:25 tron Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/09/03 19:27:57 gj Exp

DISTNAME=	xemacs-21.1.14
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/xemacs-21.1/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/xemacs-21.1/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/xemacs-21.1/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/xemacs-21.1/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/xemacs-21.1/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	XEmacs text editor version 21

DEPENDS+=	gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=	png>=1.0.11:../../graphics/png
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff
DEPENDS+=	jpeg-[0-9]*:../../graphics/jpeg

NOT_FOR_PLATFORM=	*-*-mips*	#fails purespace dumping

HAS_CONFIGURE=	YES
USE_XPM=	YES
USE_XAW=	YES
XAW_TYPE?=	3d

BUILD_DEFS+=	USE_LDAP USE_XFACE
DIST_SUBDIR=	xemacs
EXTRA_FILES=	${DISTNAME}-elc.tar.gz ${DISTNAME}-info.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.include "../../mk/bsd.prefs.mk"

.if defined(MANZ)
PLIST_SUBST+=	ELSUFX=.gz
.else
PLIST_SUBST+=	ELSUFX=
.endif

.if (${XAW_TYPE} == "standard")
WITH_DIALOGS=	--with-dialogs=athena
.else
WITH_DIALOGS=	--with-dialogs=athena3d
.endif

.if defined(USE_LDAP) && ${USE_LDAP} == YES
WITH_LDAP=	--with-ldap=yes
DEPENDS+=	openldap-[0-9]*:../../databases/openldap
.else
WITH_LDAP=	--with-ldap=no
.endif

.if defined(USE_XFACE) && ${USE_XFACE} == YES
WITH_XFACE=	--with-xface=yes
DEPENDS+=	faces>=1.6.1:../../mail/faces
.else
WITH_XFACE=	--with-xface=no
.endif

CONFIGURE_ARGS+=	${MACHINE_GNU_PLATFORM} --prefix=${PREFIX} \
			--with-clash-detection --with-mule=yes \
			--with-ncurses=no --with-session=yes \
			${WITH_DIALOGS} ${WITH_LDAP} ${WITH_XFACE} \
			--infopath="${PREFIX}/info:${X11BASE}/info:/usr/local/info" \
			--lockdir=/var/tmp/xemacs.lock \
			--site-includes=${PREFIX}/include:${WRKDIR} \
			--site-libraries=${PREFIX}/lib

CFLAGS+=		-Dunix
MAKE_ENV+=		INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-extract:
	for FILE in ${EXTRA_FILES}; do \
	  ${GTAR} xzCf ${WRKDIR} ${DISTDIR}/${DIST_SUBDIR}/$$FILE; \
	done

post-patch:
	@${RM} -f ${WRKSRC}/etc/ctags.1.orig

pre-configure:
	@${ECHO} "To compile in the support for LDAP, set the environment variable USE_LDAP."
	@${ECHO} "To compile in the support for xface, set the environment variable USE_XFACE."
	@${MKDIR} ${WRKDIR}/sys
	@${LN} -s /usr/include/soundcard.h ${WRKDIR}/sys

post-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/${DISTNAME}
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/xemacs
	@if [ "X${MANZ}" != X"" ]; then \
		${WRKSRC}/lib-src/gzip-el.sh ${PREFIX}/lib/${DISTNAME}; \
	fi

.include "../../mk/bsd.pkg.mk"
