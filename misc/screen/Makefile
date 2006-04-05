# $NetBSD: Makefile,v 1.66 2006/04/05 23:01:16 jlam Exp $

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

PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-sys-screenrc=${PKG_SYSCONFDIR}/screenrc
CONFIGURE_ARGS+=	--enable-telnet

PKG_SHELL=		bin/screen
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	etc/etcscreenrc doc/screen.1
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@EXAMPLES@,${PREFIX}/share/examples/screen,g'
SUBST_STAGE.paths=	post-patch

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
