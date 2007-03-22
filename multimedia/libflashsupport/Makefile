# $NetBSD: Makefile,v 1.1.1.1 2007/03/22 21:46:44 abs Exp $
#

PKGNAME=	libflashsupport-1.0.2098
DISTNAME=	libflashsupport-1-0-2098-i586
CATEGORIES=	multimedia
MASTER_SITES=	http://www.thinlincusergroup.se/forum/teknik/666951651/510222697/
EXTRACT_SUFX=	.rpm

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://labs.adobe.com/wiki/index.php/Flash_Player:Additional_Interface_Support_for_Linux
COMMENT=	Additional Interface Support for Linux Flash Player

USE_LANGUAGES=	# none
NO_BUILD=	YES

BUILD_DEPENDS+= rpm2pkg>=1.2:../../pkgtools/rpm2pkg
RPM2PKG=        rpm2pkg
RPM2PKGARGS=	-d ${WRKDIR} -s 3 ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_base>=9.1:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=		suse_openssl>=9.1:../../emulators/${SUSE_DIR_PREFIX}_openssl
.endif

ONLY_FOR_PLATFORM=	*-*-i386

do-extract:
	${RPM2PKG} ${RPM2PKGARGS}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/libflashsupport.so ${PREFIX}/emul/linux/usr/lib
	${INSTALL_DATA} ${WRKDIR}/doc/libflashsupport-1.0/README ${PREFIX}/share/doc/libflashsupport.README

.include "../../mk/bsd.pkg.mk"
