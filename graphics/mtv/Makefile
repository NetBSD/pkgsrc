# $NetBSD: Makefile,v 1.6 1999/07/16 22:37:19 tron Exp $

DISTNAME=		mtv-1.0.9.10
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.mpegtv.com/pub/mpeg/mpegtv/player/x86-unknown-linux-glibc/packages/RPMS/ \
			ftp://ftp.mpeg.org/pub/mpeg/mpegtv/player/x86-unknown-linux-glibc/packages/RPMS/
DISTFILES=		${DISTNAME}-1.i386.rpm SDL-0.9.9-5.i386.rpm
ONLY_FOR_PLATFORM=	NetBSD-1.4[G-Z]-i386 NetBSD-1.[5-9]*-i386

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.mpegtv.com/

DEPENDS=		suse_xforms-6.1:../../emulators/suse_xforms

DIST_SUBDIR=		mtv
LICENSE=		fee-based-commercial-use

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
NO_PATCH=		yes
NO_CONFIGURE=		yes
NO_WRKSUBDIR=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

EMULSUBDIR=		emul/linux
EMULDIR=		${PREFIX}/${EMULSUBDIR}
SBINDIR=		${PREFIX}/sbin

do-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
.for FILE in mtv mtvp
	${LN} -fs ../${EMULSUBDIR}/usr/X11R6/bin/${FILE} ${PREFIX}/bin
.endfor
	cd ${_DISTDIR} && \
	${SBINDIR}/rpm2pkg ${DISTFILES} >>${PLIST_SRC}
	@${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" >>${PLIST_SRC}
	${EMULDIR}/sbin/ldconfig -r ${EMULDIR} || ${TRUE}

show-shlib-type:
	@${ECHO} linux-${MACHINE_ARCH}

.include "../../mk/bsd.pkg.mk"
