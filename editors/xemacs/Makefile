# $NetBSD: Makefile,v 1.12 1999/08/25 13:37:35 agc Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/09/03 19:27:57 gj Exp

DISTNAME=	xemacs-21.1.6
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/xemacs-21.1/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/xemacs-21.1/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/xemacs-21.1/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/xemacs-21.1/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/xemacs-21.1/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-elc${EXTRACT_SUFX} ${DISTNAME}-info${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xemacs.org/

USE_XAW=	yes

DEPENDS+=	gdbm-1.7.3:../../databases/gdbm
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	xpm-3.4k:../../graphics/xpm

NOT_FOR_PLATFORM=	*-*-alpha *-*-mips	#fails purespace dumping

HAS_CONFIGURE=	yes

DIST_SUBDIR=	xemacs

BUILD_DEFS+=	USE_XFACE

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=	3d

WITH_DIALOGS=	--with-dialogs=athena3d

.if defined(USE_XFACE) && ${USE_XFACE} == YES
WITH_XFACE=	--with-xface=yes
DEPENDS+=	faces-1.6.1:../../mail/faces
.else
WITH_XFACE=	--with-xface=no
.endif

CONFIGURE_ARGS+=	${MACHINE_GNU_ARCH}--netbsd --prefix=${PREFIX} \
			--with-clash-detection --with-mule=yes \
			--with-ncurses=no --with-session=yes \
			${WITH_DIALOGS} ${WITH_XFACE} \
			--infopath="${PREFIX}/info:${X11BASE}/info:/usr/local/info" \
			--lockdir=/var/tmp/xemacs.lock \
			--site-includes=${PREFIX}/include:${WRKDIR} \
			--site-libraries=${PREFIX}/lib

CFLAGS+=		-Dunix
MAKE_ENV+=		INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_SCRIPT="${INSTALL_SCRIPT}"
PLIST_SRC=		${WRKDIR}/PLIST.tmp

post-patch:
	@${RM} -f ${WRKSRC}/etc/ctags.1.orig

pre-configure:
	@${ECHO} "To compile in the support for xface, set the environment variable USE_XFACE."
	@${MKDIR} ${WRKDIR}/sys
	@${LN} -s /usr/include/soundcard.h ${WRKDIR}/sys

post-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/${DISTNAME}
	@${MKDIR} ${PREFIX}/lib/xemacs
	@if [ "X${MANZ}" != X"" ]; then \
		${WRKSRC}/lib-src/gzip-el.sh ${PREFIX}/lib/${DISTNAME}; \
		GZSUFFIX=.gz; \
	fi; \
	${SED} -e 's|@.GZ@|'$$GZSUFFIX'|g' ${PKGDIR}/PLIST >${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
