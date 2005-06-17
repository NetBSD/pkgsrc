# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:23 jlam Exp $
#

DISTNAME=	trplayer-1.2.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	ftp://linux-speakup.org/pub/linux/goodies/trplayer/
EXTRACT_SUFX=	-1.i386.rpm

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.linux-speakup.org/trplayer.html
COMMENT=	Text-mode Realmedia Player

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	rpm2pkg>=1.2:../../pkgtools/rpm2pkg
DEPENDS+=	realplayer>=8.0.1:../../multimedia/realplayer
DEPENDS+=	suse_base>=7.3:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_compat>=7.3:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_slang>=7.3:../../emulators/${SUSE_DIR_PREFIX}_slang
.endif

INTERACTIVE_STAGE=	fetch		# XXX Not really!
#INTERACTIVE_STAGE=	install-depends
LICENSE=		trplayer-license
ONLY_FOR_PLATFORM=	NetBSD-1.6*-i386 NetBSD-[2-9]*-i386

WRKSRC=		${WRKDIR}
CHECK_SHLIBS=	NO
NO_BUILD=	YES

EMULDIR=	${LOCALBASE}/emul/linux
EXTRACT_ONLY=	# nothing
INFO_FILES=	trplayer.info
PLIST_SRC=	${WRKDIR}/PLIST.rpm

INSTALLATION_DIRS=	${INFO_DIR}

do-install:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC};				\
		${LOCALBASE}/sbin/rpm2pkg -d ${PREFIX} -f ${PLIST_SRC}	\
		-p emul/linux ${DISTDIR}/${DISTFILES}
	${INSTALL_DATA} ${EMULDIR}/usr/info/trplayer.info		\
		${PREFIX}/${INFO_DIR}/trplayer.info

post-install:
	${SED} -e 's,@@EMULDIR@@,${EMULDIR},'				\
		-e 's,@@LOCALBASE@@,${LOCALBASE},' ${FILESDIR}/trplayer	\
		> ${WRKSRC}/trplayer
	${INSTALL_SCRIPT} ${WRKSRC}/trplayer ${PREFIX}/bin/trplayer

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
