# $NetBSD: Makefile,v 1.3 2003/02/14 01:29:19 fredb Exp $

DISTNAME=	aim-1.5.277
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.newaol.com/aimgen/73010/
EXTRACT_SUFX=	-1.i386.rpm

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.aim.com/
COMMENT=	AOL Instant Messenger (SM)

BUILD_DEPENDS+=	rpm2pkg>=1.2:../../pkgtools/rpm2pkg
DEPENDS+=	suse_base>=${SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_compat>=${SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_x11>=${SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=	suse_gtk>=${SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_gtk

ONLY_FOR_PLATFORM= NetBSD-*-i386

CHECK_SHLIBS=	NO
NO_BUILD=	YES

EXTRACT_ONLY=	# nothing
PLIST_SRC=	${WRKDIR}/PLIST.rpm
WRKSRC=		${WRKDIR}

do-install:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${LOCALBASE}/sbin/rpm2pkg -d ${PREFIX} -f ${PLIST_SRC} \
		-p emul/linux ${DISTDIR}/${DISTFILES}
	${LN} -s ${PREFIX}/emul/linux/usr/local/bin/aim ${PREFIX}/bin/aim

.include "../../emulators/suse_linux/Makefile.application"
