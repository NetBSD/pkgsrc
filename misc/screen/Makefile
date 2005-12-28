# $NetBSD: Makefile,v 1.63 2005/12/28 17:53:24 reed Exp $

DISTNAME=	screen-4.0.2
PKGREVISION=	4
CATEGORIES=	misc shells
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU:=screen/}

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.gnu.org/software/screen/screen.html
COMMENT=	Multi-screen window manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NOT_FOR_PLATFORM=	Interix-*-* # user auth and username size fixes needed

USE_PKGINSTALL=		YES
INFO_FILES=		screen.info
PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}
FILES_SUBST+=		EXAMPLES=${PREFIX:Q}/share/examples/screen

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-sys-screenrc=${PKG_SYSCONFDIR}/screenrc
CONFIGURE_ARGS+=	--enable-telnet

PKG_SHELL=		bin/screen

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
		${PREFIX}/share/examples/screen/etcscreenrc
	${INSTALL_DATA} ${WRKSRC}/etc/screenrc				\
		${PREFIX}/share/examples/screen/screenrc
.if ${OPSYS} == "SunOS"
	cd ${WRKSRC}/terminfo &&					\
	${SETENV} TERMINFO=${PREFIX}/share/lib/terminfo			\
		/usr/5bin/tic screeninfo.src
.endif

.include "../../mk/bsd.pkg.mk"
