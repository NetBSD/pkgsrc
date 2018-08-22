# $NetBSD: Makefile,v 1.58 2018/08/22 09:46:08 wiz Exp $

DISTNAME=		vnc-3.3.3r2
PKGNAME=		vnc-3.3.3.2
PKGREVISION=		11
CATEGORIES=		net x11
MASTER_SITES=		ftp://ftp.uk.research.att.com/pub/vnc/dist/
DISTFILES=		vnc-3.3.3r2_unixsrc.tgz \
			vnc-3.3.2r2_doc.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.cl.cam.ac.uk/research/dtg/attarchive/vnc/
COMMENT=		Display X and Win32 desktops on remote X/Win32/Java displays

MAKE_JOBS_SAFE=		no

DEPENDS+=		vncviewer-[0-9]*:../../net/vncviewer

WRKSRC=			${WRKDIR}/vnc_unixsrc
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes
USE_TOOLS+=		perl:run xauth:run
BUILD_DEFS+=		IPV6_READY

BUILD_TARGET=		World

MAKE_ENV+= CC=${CC:Q}	#for make imake in Xvnc/config/imake

PKG_OPTIONS_VAR=        PKG_OPTIONS.vnc
PKG_SUPPORTED_OPTIONS=  inet6
PKG_SUGGESTED_OPTIONS=  inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		vnc-3.3.3r2-v6-20010421.diff.gz
PATCH_DIST_STRIP=	-p1
USE_TOOLS+=		patch
post-patch: patch-sockets
.PHONY: patch-sockets
patch-sockets:
	cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-sockets.c
.endif

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	vncserver
SUBST_SED.paths+=	-e 's,@X11BASE@,${X11BASE},g'
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS=	bin share/doc/vnc

.if ${OPSYS} == "SunOS"
_WRAP_EXTRA_ARGS.CC+=	-D_POSIX_SOURCE
CWRAPPERS_APPEND.cc+=	-D_POSIX_SOURCE
SPECIAL_PERMS+=	bin/Xvnc ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 2555
.endif

.if ${OS_VARIANT} == "SmartOS"
SUBST_CLASSES+=		smartos
SUBST_STAGE.smartos=	pre-configure
SUBST_FILES.smartos=	Xvnc/config/cf/svr4.cf
SUBST_SED.smartos+=	-e 's,/usr/ccs/bin/ar,/usr/bin/ar,g'
SUBST_SED.smartos+=	-e 's,/usr/ccs/bin/make,${MAKE},g'
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc ${DESTDIR}${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect ${DESTDIR}${PREFIX}/bin/vncconnect
	${SED} -e 's|/usr/local/vnc/classes|${PREFIX}/share/vnc/classes|g' \
		-e 's|/usr/bin/perl|${PERL5}|g' \
		< ${WRKSRC}/vncserver \
		> ${WRKSRC}/vncserver.local
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver.local ${DESTDIR}${PREFIX}/bin/vncserver
	cd ${WRKDIR}; \
	${INSTALL_DATA} *.GIF *.css *.gif *.jpg *.htm *.html *.pdf \
	  ${DESTDIR}${PREFIX}/share/doc/vnc

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
