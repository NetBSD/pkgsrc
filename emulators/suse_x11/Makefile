# $NetBSD: Makefile,v 1.24 2003/09/18 16:25:29 jmmv Exp $

DISTNAME=		suse_x11-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=x1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for X11 binaries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc

USE_BUILDLINK2=		# defined
EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		xshared.rpm

.include "../../mk/bsd.prefs.mk"

# directory appeared in XFree86 4.*
# if it is missing, we are using XFree86 3.* and need some additional files
.if !exists(${X11BASE}/lib/X11/locale/common)
RPMFILES+=		xf86.rpm
RPMIGNOREPATH=		usr/X11R6/bin usr/X11R6/include \
			usr/X11R6/lib/X11/app-defaults \
			usr/X11R6/lib/X11/doc usr/X11R6/lib/X11/fonts \
			usr/X11R6/lib/X11/x11perfcomp
.endif

post-install:
	@${GREP} "^@exec.*.so" ${PLIST_SRC} | 				\
		${SED} -e 's,.*/\(.*\.so\)\.\([0-9]\),@exec ${LN} -sf 	\
			\1.\2 %D/${EMULSUBDIR}/usr/X11R6/lib/\1,' 	\
			>> ${PLIST_SRC}
	@${GREP} "^@unexec rm -f" ${PLIST_SRC} |                         \
		${SED} -e 's,\(.*\)\.[0-9],\1,' >> ${PLIST_SRC}
	@for link in `${GREP} "^@exec ln.*.so" ${PLIST_SRC} |		\
		${SED} -e 's,.*/\(.*\.so\.[0-9]\),\1,'`; do		\
		cd ${EMULDIR}/usr/X11R6/lib && ${LN} -sf $$link $${link%.[0-9]};					\
	done

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
