# $NetBSD: Makefile,v 1.1.1.1 1999/08/24 21:24:57 tron Exp $

DISTNAME=		suse_devel-6.1
CATEGORIES=		emulators devel
MASTER_SITES=		ftp://ftp.suse.com/pub/suse/i386/6.1/suse/d1/ \
			ftp://ftp.cs.unm.edu/mirrors/SuSE61/suse/d1/
DISTFILES=		bin86.rpm binutils.rpm egcs.rpm g77.rpm gpp.rpm \
			libc.rpm linclude.rpm make.rpm

MAINTAINER=		wennmach@geo.Uni-Koeln.DE
HOMEPAGE=		http://www.suse.com/

DEPENDS=		suse_base-6.1:../suse_base

ONLY_FOR_PLATFORM=	NetBSD-*-i386

DIST_SUBDIR=		suse
MIRROR_DISTFILE= 	no

EXTRACT_ONLY=		# empty
NO_BUILD=               yes
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
