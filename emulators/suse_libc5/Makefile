# $NetBSD: Makefile,v 1.7 1999/05/24 20:39:41 tv Exp $

DISTNAME=		shlibs5
PKGNAME=		suse_libc5-6.1
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.suse.com/pub/suse/i386/6.1/suse/a1/ \
			ftp://ftp.cs.unm.edu/mirrors/SuSE61/suse/a1/
EXTRACT_SUFX=		.rpm

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS=		suse_base-6.1:../suse_base

DIST_SUBDIR=		suse
MIRROR_DISTFILE=	no

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
NO_WRKSUBDIR=		yes
MANCOMPRESSED=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

EMULSUBDIR=		emul/linux
EMULDIR=		${PREFIX}/${EMULSUBDIR}
SBINDIR=		${PREFIX}/sbin

do-install:
	cd ${_DISTDIR} && \
	${SBINDIR}/rpm2pkg ${DISTFILES} >${PLIST_SRC}
	@${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" >>${PLIST_SRC}
	${EMULDIR}/sbin/ldconfig -r ${EMULDIR} || ${TRUE}

show-shlib-type:
	@${ECHO} linux-${MACHINE_ARCH}

.include "../../mk/bsd.pkg.mk"
