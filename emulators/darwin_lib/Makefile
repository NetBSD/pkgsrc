# $NetBSD: Makefile,v 1.1.1.1 2003/09/28 23:33:52 manu Exp $

DISTNAME=	darwin_lib-6.6.2
CATEGORIES=	emulators
MASTER_SITES=	http://www.opendarwin.org/downloads/6.6.2/RPMS/ \
		http://www.opendarwin.org/downloads/6.6.2/RPMS/${DARWIN_ARCH}/
DISTFILES=	org.opendarwin.Libsystem-6.6.2-4.fat.rpm \
		org.opendarwin.Libm-6.6.2-4.fat.rpm \
		org.opendarwin.cctools-6.6.2-4.fat.rpm \
		org.opendarwin.ncurses-6.6.2-4.fat.rpm \
		org.opendarwin.IOKitUser-6.6.2-4.fat.rpm \
		org.opendarwin.XFree86-6.6.2-4.${DARWIN_ARCH}.rpm

MAINTAINER=	abacau@yahoo.com.au
HOMEPAGE=	http://www.opendarwin.org/
COMMENT=	Darwin compatiblity libraries (including X11)

BUILD_DEPENDS=	rpm2pkg>=1.3:../../pkgtools/rpm2pkg

ONLY_FOR_PLATFORM=	NetBSD-1.6Z*-powerpc NetBSD-1.6Z*-i386 \
			NetBSD-[2-9]*-powerpc NetBSD-[2-9]*-i386

PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

DARWIN_ARCH=	${MACHINE_ARCH:C/powerpc/ppc/}

RPM2PKG=	rpm2pkg
RPMARGS=	-d ${PREFIX} -f ${PLIST_SRC} -p emul/darwin -i ./Developer \
		-i ./usr/X11R6/lib/X11/doc/html -i ./usr/share/man \
		-i ./usr/include -i ./usr/X11R6/man -i ./usr/X11R6/include \
		-i ./usr/local/include -i ./usr/local/man
.for TEMP in ${DISTFILES}
RPMARGS+=	${DISTDIR}/${TEMP}
.endfor

EXTRACT_ONLY=	# empty
NO_BUILD=	1

do-install:
	${RM} -f ${WRKDIR}/PLIST_DYNAMIC
	${RPM2PKG} ${RPMARGS}
	${MKDIR} /emul
	# Avoid a symlink left from a previous installation
	${TEST} -L /emul/darwin && ${RM} /emul/darwin || ${TRUE}
	${LN} -sf ${PREFIX}/emul/darwin /emul/darwin

.include "../../mk/bsd.pkg.mk"
