# $NetBSD: Makefile,v 1.48.2.1 2003/12/07 16:52:47 agc Exp $

DISTNAME=	screen-4.0.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU:=screen/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/screen/screen.html
COMMENT=	Multi-screen window manager

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
INFO_FILES=		screen.info
PLIST_SUBST=		DISTNAME=${DISTNAME}

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-sys-screenrc=${PKG_SYSCONFDIR}/screenrc
CONFIGURE_ARGS+=	--enable-telnet

.include "../../mk/bsd.prefs.mk"

post-patch:
	@for file in etc/etcscreenrc doc/screen.1; do 			\
		${MV} ${WRKSRC}/$$file ${WRKSRC}/$$file.orig;		\
		${SED} ${FILES_SUBST_SED}				\
			${WRKSRC}/$$file.orig > ${WRKSRC}/$$file;	\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/screen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc			\
		${PREFIX}/share/examples/screen/screenrc
.if ${OPSYS} == "SunOS"
	cd ${WRKSRC}/terminfo &&					\
	${SETENV} TERMINFO=${PREFIX}/share/lib/terminfo			\
		/usr/5bin/tic screeninfo.src
.endif

.include "../../mk/bsd.pkg.mk"
