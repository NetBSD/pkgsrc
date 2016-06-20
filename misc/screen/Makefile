# $NetBSD: Makefile,v 1.97 2016/06/20 16:04:44 ryoon Exp $

DISTNAME=	screen-4.4.0
CATEGORIES=	misc shells
MASTER_SITES=	${MASTER_SITE_GNU:=screen/}

MAINTAINER=	kimmo@suominen.com
HOMEPAGE=	http://www.gnu.org/software/screen/screen.html
COMMENT=	Multi-screen window manager
LICENSE=	gnu-gpl-v3

# In file included from list_display.c:36:
# In file included from ./screen.h:150:
# ./display.h:154:19: error: use of undeclared identifier 'T_N'
#MAKE_JOBS_SAFE=	no

.include "options.mk"

NOT_FOR_PLATFORM=	Interix-*-* # user auth and username size fixes needed

PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-sys-screenrc=${PKG_SYSCONFDIR}/screenrc
CONFIGURE_ARGS+=	--enable-telnet

PKG_SHELL=		bin/screen

USE_TOOLS+=		makeinfo
INFO_FILES=		YES

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	etc/etcscreenrc doc/screen.1
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@EXAMPLES@,${PREFIX}/share/examples/screen,g'
SUBST_STAGE.paths=	post-patch

PLIST_VARS+=		terminfo

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-D_XOPEN_SOURCE=500 -D__EXTENSIONS__
.  if ${CURSES_DEFAULT} == "curses"
INSTALLATION_DIRS+=	share/lib/terminfo
PLIST.terminfo=		yes
post-install: screen-terminfo
.  endif
.endif

INSTALLATION_DIRS+=	share/examples/screen

.if empty(UNPRIVILEGED:M[Yy][Ee][Ss])
SPECIAL_PERMS+=		bin/${DISTNAME} ${SETUID_ROOT_PERMS}
.endif

post-install:
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
		/usr/bin/tic screeninfo.src

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
