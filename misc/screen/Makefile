# $NetBSD: Makefile,v 1.84 2012/09/15 09:14:53 apb Exp $

DISTNAME=	screen-4.0.3
PKGREVISION=	5
CATEGORIES=	misc shells
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		http://people.freebsd.org/~cy/distfiles/
#		${MASTER_SITE_GNU:=screen/}

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.gnu.org/software/screen/screen.html
COMMENT=	Multi-screen window manager
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

NOT_FOR_PLATFORM=	Interix-*-* # user auth and username size fixes needed

PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-sys-screenrc=${PKG_SYSCONFDIR}/screenrc
CONFIGURE_ARGS+=	--enable-telnet

PKG_SHELL=		bin/screen
INFO_FILES=		YES

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	etc/etcscreenrc doc/screen.1
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@EXAMPLES@,${PREFIX}/share/examples/screen,g'
SUBST_STAGE.paths=	post-patch

PLIST_VARS+=		terminfo
.if (${OPSYS} == "SunOS") && exists(/usr/5bin/tic)
INSTALLATION_DIRS+=	share/lib/terminfo
PLIST.terminfo=		yes
post-install: screen-terminfo
.endif

.if empty(UNPRIVILEGED:M[Yy][Ee][Ss])
SPECIAL_PERMS+=		bin/${DISTNAME} ${SETUID_ROOT_PERMS}
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/screen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc			\
		${DESTDIR}${PREFIX}/share/examples/screen/etcscreenrc
	${INSTALL_DATA} ${WRKSRC}/etc/screenrc				\
		${DESTDIR}${PREFIX}/share/examples/screen/screenrc
.if !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
	chmod -s ${DESTDIR}${PREFIX}/bin/${DISTNAME}
.endif

.PHONY: screen-terminfo
screen-terminfo:
	cd ${WRKSRC}/terminfo &&					\
	${SETENV} TERMINFO=${DESTDIR}${PREFIX}/share/lib/terminfo	\
		/usr/5bin/tic screeninfo.src

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
