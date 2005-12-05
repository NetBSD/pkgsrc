# $NetBSD: Makefile,v 1.54 2005/12/05 20:49:50 rillig Exp $

DISTNAME=	xmcd-3.0.2
PKGREVISION=    5
CATEGORIES=	audio
MASTER_SITES=	http://www.ibiblio.org/tkan/download/xmcd/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ibiblio.org/tkan/xmcd/
COMMENT=	Motif CD player

PATCH_SITES=		${HOMEPAGE}
PATCHFILES=		xmcd-3.0.2-proxyauth-patch
PATCH_DIST_STRIP=	-p1

WRKSRC=			${WRKDIR}/xmcd-3.0
USE_PKGINSTALL=		yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

USE_IMAKE=		yes
MAKE_ENV+=		BATCH_BINDIR=${PREFIX}/bin
MAKE_ENV+=		BATCH_LIBDIR=${PREFIX}/lib/X11
MAKE_ENV+=		BATCH_MANDIR=${PREFIX}/man/man1
MAKE_ENV+=		SHELL=${SH:Q}

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

_SETUID_ROOT=	${ROOT_USER} ${ROOT_GROUP} 4711
SPECIAL_PERMS=	${ARCHBIN}/cda ${_SETUID_ROOT}
SPECIAL_PERMS+=	${ARCHBIN}/xmcd ${_SETUID_ROOT}

CFILES=		common.cfg device.cfg wwwwarp.cfg
.for FILE in ${CFILES}
CONF_FILES+=	${XMCDDIR}/config/${FILE}.dist ${XMCDDIR}/config/${FILE}
.endfor
REQD_DIRS=	${XMCDDIR} ${XMCDDIR}/cdinfo ${XMCDDIR}/config ${XMCDDIR}/discog

pre-configure:
	cd ${WRKSRC} && \
	for f in libdi_d/config.sh misc_d/start.sh install.sh; do \
		${SED} -e "s/@MACHINE_ARCH@/${MACHINE_ARCH}/" $$f > $$f.new; \
		${MV} -f $$f.new $$f; \
	done

post-install:
	if [ -n "${_STRIPFLAG_INSTALL}" ]; then				\
		for file in cda xmcd gobrowser; do			\
			strip ${ARCHBIN}/$$file;			\
		done;							\
	fi

.if ${OPSYS} != "SunOS"
.include "../../devel/ncurses/buildlink3.mk"
.endif
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
