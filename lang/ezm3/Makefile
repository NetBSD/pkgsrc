# $NetBSD: Makefile,v 1.2 2004/01/06 06:43:31 xtraeme Exp $

DISTNAME=	ezm3-1.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.FreeBSD.org/pub/FreeBSD/development/CVSup/ezm3/
DISTFILES=	${DISTNAME}-src.tar.bz2 ${BOOTSTRAP}

MAINTAINER=	motoyuki@bsdclub.org
HOMEPAGE=	http://www.polstra.com/projects/freeware/ezm3/
COMMENT=	Easier, more portable Modula-3 distribution for building CVSup

DIST_SUBDIR=		ezm3
USE_GMAKE=		yes
USE_X11=		yes

INSTALL_TARGET=		all
MAKE_ARGS+=		M3OPTIONS="-DBUILD_ALL -DSHIP_ALL"
PLIST_SUBST+=		TARGET=${TARGET} TARGETDIR=${TARGETDIR}
PLIST_SUBST+=		WORDSIZE=${WORDSIZE}

# XXX CFLAGS has to be empty, because if it's not, the build
# XXX process will fail.

.include "../../mk/bsd.prefs.mk"
CFLAGS:=			
EZM3ROOT=		${PREFIX}/ezm3

ONLY_FOR_PLATFORM=      FreeBSD-*-i386 NetBSD-*-i386

.if ${OPSYS} == "FreeBSD"
BOOTSTRAP=	${DISTNAME}-FreeBSD4-boot.tar.bz2
TARGET=		FreeBSD4
TARGETDIR=	freebsd-1
.elif ${OPSYS} == "NetBSD"
BOOTSTRAP=      ${DISTNAME}-NetBSDi386-boot.tar.bz2
TARGET=         NetBSDi386
TARGETDIR=      netbsd-1
.endif

PROGS=		bin/m3build bin/m3bundle bin/m3ship

do-configure:
	cd ${WRKSRC}/m3config/src && \
	    ${MV} -f ${TARGET} ${TARGET}.bak && \
	    ${SED} -e "/^INSTALL_ROOT = /s|\".*\"|\"${EZM3ROOT}\"|" \
		   -e "/^X11ROOT = /s|\".*\"|\"${X11BASE}/lib\"|" \
		   ${TARGET}.bak > ${TARGET}

do-build:
	${RM} -rf ${WRKSRC}/${TARGET}
	cd ${WRKSRC} && ${SU_CMD} '${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}'

do-install:
	for i in ${PROGS}; do strip ${EZM3ROOT}/$$i; done

.include "../../mk/bsd.pkg.mk"
