# $NetBSD: Makefile,v 1.77 2012/10/02 23:48:14 asau Exp $

DISTNAME=	xmcd-3.0.2
PKGREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	http://www.ibiblio.org/tkan/download/xmcd/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amb.org/xmcd/
COMMENT=	Motif CD player

PATCH_SITES=		${HOMEPAGE}
PATCHFILES=		xmcd-3.0.2-proxyauth-patch
PATCH_DIST_STRIP=	-p1

WRKSRC=			${WRKDIR}/xmcd-3.0

USE_IMAKE=		yes
MAKE_ENV+=		BATCH_BINDIR=${DESTDIR}${PREFIX}/bin
MAKE_ENV+=		BATCH_LIBDIR=${DESTDIR}${PREFIX}/lib/X11
MAKE_ENV+=		BATCH_MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
MAKE_ENV+=		REAL_BINDIR=${PREFIX}/bin
MAKE_ENV+=		REAL_LIBDIR=${PREFIX}/lib/X11
MAKE_ENV+=		REAL_MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_ENV+=		REAL_XMCDLIB=${PREFIX}/lib/X11/xmcd
MAKE_ENV+=		REAL_DISCOGDIR=${PREFIX}/lib/X11/xmcd/discog
MAKE_ENV+=		BATCH_MANSUFFIX=1
MAKE_ENV+=		SHELL=${SH:Q}

CHECK_PERMS_SKIP+=	lib/X11/xmcd/discog/*

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-S]*-*

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
ARCH=	Solaris
.else
ARCH=	${OPSYS}
.endif

ARCHBIN=	${PREFIX}/lib/X11/xmcd/bin-${ARCH}-${MACHINE_ARCH}
XMCDDIR=	${PREFIX}/lib/X11/xmcd
PLIST_SUBST+=	ARCH=${ARCH:Q}

SPECIAL_PERMS=	${ARCHBIN}/cda ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${ARCHBIN}/xmcd ${SETUID_ROOT_PERMS}

CFILES=		common.cfg device.cfg wwwwarp.cfg
.for f in ${CFILES}
CONF_FILES+=	${XMCDDIR}/config/${f}.dist ${XMCDDIR}/config/${f}
.endfor
REQD_DIRS=	${XMCDDIR} ${XMCDDIR}/cdinfo ${XMCDDIR}/config ${XMCDDIR}/discog

SUBST_CLASSES+=		xmcd
SUBST_STAGE.xmcd=	pre-configure
SUBST_MESSAGE.xmcd=	Replacing MACHINE_ARCH
SUBST_FILES.xmcd=	libdi_d/config.sh misc_d/start.sh install.sh
SUBST_VARS.xmcd=	MACHINE_ARCH

INSTALLATION_DIRS=	bin

post-install:
	for file in cda xmcd gobrowser; do			\
		strip ${DESTDIR}${ARCHBIN}/$$file;		\
	done;

.if ${OPSYS} != "SunOS"
.include "../../devel/ncurses/buildlink3.mk"
.endif
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
