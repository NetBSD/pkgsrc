# $NetBSD: Makefile,v 1.1.1.1 2001/03/11 23:22:50 dmcmahill Exp $

DISTNAME=	netscape-4.7-3.alpha
PKGNAME=	osf1_lib-1.0
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.support.compaq.com/private/alpha-tools-software/netscape/
EXTRACT_SUFX=	.rpm

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.support.compaq.com/alpha-tools/software/index.html
COMMENT=	DEC/Compaq OSF-1/Tru64 compatibility package for netscape

RPM2PKG=	${LOCALBASE}/sbin/rpm2pkg
BUILD_DEPENDS+=	${RPM2PKG}:../../pkgtools/rpm2pkg

ONLY_FOR_PLATFORM=	NetBSD-*-alpha

RESTRICTED=		"COMPAQ Licensed Software"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

EMULSUBDIR=		emul/osf1
EMULDIR=		${PREFIX}/${EMULSUBDIR}

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}

RPMARGS=	-i usr/lib -i usr/bin ${DISTDIR}/${DISTFILES}

CHECK_SHLIBS=	no
SHLIB_HANDLING=	no

USE_X11=	yes

do-install:
	${RM} -f ${WRKDIR}/PLIST_DYNAMIC
	${INSTALL_DATA_DIR} ${EMULDIR}
	${RPM2PKG} -d ${PREFIX} -p ${EMULSUBDIR} ${RPMARGS}
	(cd ${EMULDIR}; ${MKDIR} usr/lib/X11)
	(cd ${EMULDIR}/usr/lib/X11; ${LN} -fs ${X11BASE}/lib/X11/locale .)

post-install:
	PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
