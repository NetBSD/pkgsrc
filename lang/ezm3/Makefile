# $NetBSD: Makefile,v 1.9 2005/05/09 12:23:23 xtraeme Exp $

DISTNAME=	ezm3-1.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.FreeBSD.org/pub/FreeBSD/development/CVSup/ezm3/
DISTFILES=	${DISTNAME}-src.tar.bz2 ${BOOTSTRAP}

MAINTAINER=	motoyuki@bsdclub.org
HOMEPAGE=	http://www.polstra.com/projects/freeware/ezm3/
COMMENT=	Easier, more portable Modula-3 distribution for building CVSup

DIST_SUBDIR=		ezm3
USE_GNU_TOOLS+=		make
INSTALL_TARGET=		all
MAKE_ARGS+=		M3OPTIONS="-DBUILD_ALL -DSHIP_ALL"
PLIST_SUBST+=		TARGET=${TARGET} TARGETDIR=${TARGETDIR}

# XXX CFLAGS has to be empty, because if it's not, the build
# XXX process will fail.

.include "../../mk/bsd.prefs.mk"
CFLAGS:=
EZM3ROOT=		${PREFIX}/ezm3
BUILDLINK_PASSTHRU_DIRS+=	${EZM3ROOT}

# XXX: This may well work for some others.
ONLY_FOR_PLATFORM=      FreeBSD-*-i386 NetBSD-*-i386 Linux-*-i386

.if ${OPSYS} == "FreeBSD"
BOOTSTRAP=	${DISTNAME}-FreeBSD4-boot.tar.bz2
TARGET=		FreeBSD4
TARGETDIR=	freebsd-1
.elif ${OPSYS} == "NetBSD"
BOOTSTRAP=      ${DISTNAME}-NetBSDi386-boot.tar.bz2
TARGET=         NetBSDi386
TARGETDIR=      netbsd-1
.elif ${OPSYS} == "Linux"
BOOTSTRAP=	${DISTNAME}-LINUXLIBC6-boot.tar.bz2
TARGET=		LINUXLIBC6
TARGETDIR=	linux-libc6
.endif

do-configure:
	cd ${WRKSRC}/m3config/src && \
	    ${MV} -f ${TARGET} ${TARGET}.bak && \
	    ${SED} -e "/^INSTALL_ROOT = /s|\".*\"|\"${EZM3ROOT}\"|" \
		   -e "/^X11ROOT = /s|\".*\"|\"${X11BASE}/lib\"|" \
		   ${TARGET}.bak > ${TARGET}

pre-build:
	${RM} -rf ${WRKSRC}/${TARGET}

do-build:
	@${ECHO}
	@${ECHO} "======================================================================";
	@${ECHO} "As per the website, it is NOT possible to separate the build process"
	@${ECHO} "from the installation process."
	@${ECHO} "'${MAKE} install' will build AND install the package."
	@${ECHO} "======================================================================";

.include "../../mk/bsd.pkg.mk"
