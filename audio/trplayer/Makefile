# $NetBSD: Makefile,v 1.1.1.1 2002/08/31 20:04:53 fredb Exp $
#

DISTNAME=	trplayer-1.2.0
CATEGORIES=	audio
MASTER_SITES=	ftp://linux-speakup.org/pub/linux/goodies/trplayer/
EXTRACT_SUFX=	-1.i386.rpm

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.linux-speakup.org/trplayer.html
COMMENT=	Text-mode Realmedia Player

BUILD_DEPENDS+=	rpm2pkg-1.2:../../pkgtools/rpm2pkg
DEPENDS+=	realplayer>=8.0.1:../../audio/realplayer
DEPENDS+=	suse_base>=7.3:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_compat>=7.3:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_libc5>=7.3:../../emulators/${SUSE_DIR_PREFIX}_libc5
DEPENDS+=	suse_slang>=7.3:../../emulators/${SUSE_DIR_PREFIX}_slang

LICENSE=	trplayer-license
ONLY_FOR_PLATFORM= NetBSD-1.6*-i386

CHECK_SHLIBS=	NO
NO_BUILD=	YES

EMULDIR=	${LOCALBASE}/emul/linux
EXTRACT_ONLY=	# nothing
INFO_FILES=	trplayer.info
PLIST_SRC=	${WRKDIR}/PLIST.rpm
WRKSRC=		${WRKDIR}

do-install:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC};				\
		${LOCALBASE}/sbin/rpm2pkg -d ${PREFIX} -f ${PLIST_SRC}	\
		-p emul/linux ${DISTDIR}/${DISTFILES}
	${INSTALL_DATA} ${EMULDIR}/usr/info/trplayer.info		\
		${PREFIX}/info/trplayer.info

post-install:
	${SED} -e 's,@@EMULDIR@@,${EMULDIR},'				\
		-e 's,@@LOCALBASE@@,${LOCALBASE},' ${FILESDIR}/trplayer	\
		> ${WRKSRC}/trplayer
	${INSTALL_SCRIPT} ${WRKSRC}/trplayer ${PREFIX}/bin/trplayer

.include "../../mk/texinfo.mk"
.include "../../emulators/suse_linux/Makefile.application"
