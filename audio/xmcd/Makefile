# $NetBSD: Makefile,v 1.48 2004/10/03 00:13:10 tv Exp $

DISTNAME=	xmcd-3.0.2
PKGREVISION=    4
CATEGORIES=	audio
MASTER_SITES=	http://www.ibiblio.org/tkan/download/xmcd/src/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.ibiblio.org/tkan/xmcd/
COMMENT=	Motif CD player

PATCH_SITES=		${HOMEPAGE}
PATCHFILES=		xmcd-3.0.2-proxyauth-patch
PATCH_DIST_STRIP=	-p1

WRKSRC=			${WRKDIR}/xmcd-3.0
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

USE_IMAKE=		yes
MAKE_ENV+=		BATCH_BINDIR=${PREFIX}/bin
MAKE_ENV+=		BATCH_LIBDIR=${PREFIX}/lib/X11
MAKE_ENV+=		BATCH_MANDIR=${PREFIX}/man/man1
MAKE_ENV+=		SHELL=${SH}

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]* NetBSD-1.6[A-S]*

ARCHBIN=	${PREFIX}/lib/X11/xmcd/bin-${OPSYS}-${MACHINE_ARCH}
XMCDDIR=	${PREFIX}/lib/X11/xmcd

_SETUID_ROOT=	${ROOT_USER} ${ROOT_GROUP} 4711
SPECIAL_PERMS=	${ARCHBIN}/cda ${_SETUID_ROOT}
SPECIAL_PERMS+=	${ARCHBIN}/xmcd ${_SETUID_ROOT}

SFILES=		common.cfg device.cfg wwwwarp.cfg
.for FILE in ${SFILES}
SUPPORT_FILES+=	${XMCDDIR}/config/${FILE}.dist ${XMCDDIR}/config/${FILE}
.endfor
MAKE_DIRS=	${XMCDDIR} ${XMCDDIR}/cdinfo ${XMCDDIR}/config ${XMCDDIR}/discog

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

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
