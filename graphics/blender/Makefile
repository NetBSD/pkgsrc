# $NetBSD: Makefile,v 1.9 2001/11/27 03:49:44 hubertf Exp $
#

PKGNAME=	blender-2.11nb4
CATEGORIES=	graphics
MASTER_SITES=	ftp://www.blender.nl/pub/

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://www.blender.nl
COMMENT=	GUI based raytracer

RESTRICTED=	"Only the original, unmodified package may be freely distributed"
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

NO_BUILD=	yes
CHECK_SHLIBS=	NO

# To be updated as other platforms PLIST will be built
ONLY_FOR_PLATFORM= *-*-powerpc

.if (${MACHINE_ARCH} == "alpha")
.if !exists(/emul/linux/lib/ld.so.1)
IGNORE=		"${PKGNAME} requires Linux libraries - see compat_linux(8)"
.endif
DISTNAME=	blender2.11-linux-glibc2.1.3-alpha
#
.elif (${MACHINE_ARCH} == "i386")
DEPENDS+=	suse_linux>=6.4:../../emulators/suse_linux
DISTNAME=	blender2.11-linux-glibc2.1.2-i386-static
PLIST_ARCH=	linux-i386
#
.elif (${MACHINE_ARCH} == "sparc")
.if !exists(/emul/sunos/usr/lib/ld.so)
IGNORE=		"${PKGNAME} requires SunOS libraries - see compat_sunos(8)"
.endif
DISTNAME=	blender2.11-solaris-2.6-sparc
EXTRACT_SUFX=	.tar.Z
#
.elif (${MACHINE_ARCH} == "powerpc")
.if !exists(/emul/linux/lib/ld.so.1)
IGNORE=		"${PKGNAME} requires Linux libraries - see compat_linux(8)"
.endif
DEPENDS+=	linuxppc_lib>=2000.4.2:../../emulators/linuxppc_lib
DISTNAME=	blender2.11-linux-glibc2.1.3-powerpc-static
PLIST_ARCH=	linux-powerpc
#
.else
DISTNAME=	# dummy, don't break pkg system
IGNORE=		"Your platform is not supported and the package is buggy!"
.endif

PLIST_SRC=	${PKGDIR}/PLIST.${PLIST_ARCH}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/blender
	${CP} -Rp ${WRKSRC}/* ${PREFIX}/lib/blender/
	${LN} -sf ../lib/blender/blender ${PREFIX}/bin/blender

.include "../../mk/bsd.pkg.mk"
