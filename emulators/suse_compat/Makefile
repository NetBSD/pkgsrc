# $NetBSD: Makefile,v 1.1.1.1 1999/05/21 00:55:59 tron Exp $

DISTNAME=	compat
PKGNAME=	suse_compat-6.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.suse.com/pub/suse/i386/6.1/suse/a2/ \
		ftp://ftp.cs.unm.edu/mirrors/SuSE61/suse/a2/
EXTRACT_SUFX=	.rpm
ONLY_FOR_ARCHS=	i386

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.suse.com/

DEPENDS+=	suse_base-6.1:../suse_base

DIST_SUBDIR=	suse
MIRROR_DISTFILE= no

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes
MANCOMPRESSED=	yes
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

EMULSUBDIR=	emul/linux
EMULDIR=	${PREFIX}/${EMULSUBDIR}
SBINDIR=	${PREFIX}/sbin

do-install:
		cd ${_DISTDIR} && \
		${SBINDIR}/rpm2pkg ${DISTFILES} >${PLIST_SRC}
		@${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" >>${PLIST_SRC}
		${EMULDIR}/sbin/ldconfig -r ${EMULDIR} || ${TRUE}

show-shlib-type:
		@${ECHO} linux-${MACHINE_ARCH}

.include "../../mk/bsd.pkg.mk"
