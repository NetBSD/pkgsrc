# $NetBSD: Makefile,v 1.64 2006/07/08 00:30:26 minskim Exp $

DISTNAME=	nas-1.8.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://nas.codebrilliance.com/nas/ \
		ftp://ftp.uni-duisburg.de/Sound/NAS/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://radscan.com/nas.html
COMMENT=	Network Audio System

DEPENDS+=	p5-perl-headers-${OS_VERSION}{,nb*}:../../devel/p5-perl-headers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake perl:run
USE_IMAKE=		yes

PKG_SYSCONFSUBDIR=	nas

REPLACE_PERL+=		clients/audio/auscope/auscope

SUBST_CLASSES+=		sysconf ossaudio mungeman

SUBST_STAGE.sysconf=	pre-configure
SUBST_FILES.sysconf=	config/NetAudio.def
SUBST_SED.sysconf=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"

SUBST_STAGE.ossaudio=	pre-configure
SUBST_FILES.ossaudio=	server/nasd.conf.eg server/dda/voxware/auvoxware.c
SUBST_SED.ossaudio=	-e "s|@DEVOSSAUDIO@|${DEVOSSAUDIO}|g"

SUBST_STAGE.mungeman=	pre-configure
SUBST_FILES.mungeman=	config/mungeman
SUBST_SED.mungeman=	-e 's|^ *\#|\#|g'

.include "../../mk/bsd.prefs.mk"

.if defined(UNPRIVILEGED) && !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
SUBST_CLASSES+=		owngrp
SUBST_MESSAGE.owngrp=	Fixing hardcoded owner/group.
SUBST_STAGE.owngrp=	post-configure
SUBST_FILES.owngrp=	clients/audio/auconvert/makefile \
			clients/audio/auctl/makefile \
			clients/audio/audemo/makefile \
			clients/audio/audial/makefile \
			clients/audio/auedit/makefile \
			clients/audio/auinfo/makefile \
			clients/audio/aupanel/makefile \
			clients/audio/auphone/makefile \
			clients/audio/auplay/makefile \
			clients/audio/aurecord/makefile \
			clients/audio/auscope/Makefile \
			clients/audio/autool/makefile \
			clients/audio/auwave/makefile \
			clients/audio/examples/makefile \
			clients/audio/util/makefile \
			clients/audio/widgets/makefile \
			clients/audio/Makefile \
			clients/Makefile config/Makefile doc/Makefile \
			doc/man/lib/Makefile doc/man/Makefile \
			include/audio/Makefile include/Makefile \
			lib/Makefile lib/audio/makefile \
			Makefile server/Makefile
SUBST_SED.owngrp=	-e 's/-c -o root -g wheel/-c -o ${UNPRIVILEGED_USER} -g ${UNPRIVILEGED_GROUP}/g'
.endif

.if ${OPSYS} == "SunOS"
post-install:
	${LN} -s ${PREFIX}/lib/libaudio.so.2.4 ${PREFIX}/lib/libaudio.so.2
.endif

PLIST_SRC=	${PKGDIR}/PLIST.clients

.if ${OPSYS} != "Interix"
.  if (${MACHINE_ARCH} == "i386") || \
      (${MACHINE_ARCH} == "x86_64") || \
      (${MACHINE_ARCH} == "sparc")
.    include "../../mk/oss.buildlink3.mk"
EGDIR=		${PREFIX}/share/examples/nas
CONF_FILES=	${EGDIR}/nasd.conf.eg ${PKG_SYSCONFDIR}/nasd.conf
.    if ${OPSYS} != "SunOS"
PLIST_SRC+=	${PKGDIR}/PLIST.voxware
.    endif
PLIST_SRC+=	${PKGDIR}/PLIST.server
.  endif
.endif

pre-configure:
	cd ${WRKSRC}/config && ${SETENV} ${CONFIGURE_ENV} ./configure

.include "../../mk/bsd.pkg.mk"
