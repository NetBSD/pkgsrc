# $NetBSD: Makefile,v 1.89 2012/10/02 23:48:01 asau Exp $

DISTNAME=	nas-1.9.1.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nas/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://nas.sourceforge.net/
COMMENT=	Network Audio System
LICENSE=	mit # with no-advertisement clause

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# 1) uses dia library before it is built
# 2) make succeeds even with failures, making this problem non-obvious
MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake yacc lex makedepend
USE_IMAKE=		yes

PKG_SYSCONFSUBDIR=	nas

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	pre-configure
SUBST_FILES.sysconf=	config/NetAudio.def
SUBST_SED.sysconf=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"

SUBST_CLASSES+=		ossaudio
SUBST_STAGE.ossaudio=	pre-configure
SUBST_FILES.ossaudio=	server/nasd.conf.eg server/dda/voxware/auvoxware.c
SUBST_SED.ossaudio=	-e "s|@DEVOSSAUDIO@|${DEVOSSAUDIO}|g"

SUBST_CLASSES+=		mungeman
SUBST_STAGE.mungeman=	pre-configure
SUBST_FILES.mungeman=	config/mungeman
SUBST_SED.mungeman=	-e 's|^ *\#|\#|g'

.include "../../mk/bsd.prefs.mk"

.if defined(UNPRIVILEGED) && !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
SUBST_CLASSES+=		owngrp
SUBST_MESSAGE.owngrp=	Fixing hardcoded owner/group.
SUBST_STAGE.owngrp=	post-configure
SUBST_FILES.owngrp=	clients/audio/auconvert/Makefile \
			clients/audio/auctl/Makefile \
			clients/audio/audemo/Makefile \
			clients/audio/audial/Makefile \
			clients/audio/auedit/Makefile \
			clients/audio/auinfo/Makefile \
			clients/audio/aupanel/Makefile \
			clients/audio/auphone/Makefile \
			clients/audio/auplay/Makefile \
			clients/audio/aurecord/Makefile \
			clients/audio/autool/Makefile \
			clients/audio/auwave/Makefile \
			clients/audio/examples/Makefile \
			clients/audio/util/Makefile \
			clients/audio/widgets/Makefile \
			clients/audio/Makefile \
			clients/Makefile config/Makefile doc/Makefile \
			doc/man/lib/Makefile doc/man/Makefile \
			include/audio/Makefile include/Makefile \
			lib/Makefile lib/audio/Makefile \
			Makefile server/Makefile
SUBST_SED.owngrp=	-e 's/-c -o root -g wheel/-c -o ${UNPRIVILEGED_USER} -g ${UNPRIVILEGED_GROUP}/g'
.endif

REPLACE_SH=		clients/audio/util/checkmail

PLIST_SRC=	${PKGDIR}/PLIST.clients

.if ${OPSYS} != "Darwin" && ${OPSYS} != "Interix"
RCD_SCRIPTS=	nasd
PLIST_SRC+=	${PKGDIR}/PLIST.server
EGDIR=		${PREFIX}/share/examples/nas
CONF_FILES=	${EGDIR}/nasd.conf.eg ${PKG_SYSCONFDIR}/nasd.conf

.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || \
      ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" || ${OPSYS} == "UnixWare"
.  include "../../mk/oss.buildlink3.mk"
.  endif
.endif

pre-configure:
	cd ${WRKSRC}/config && ${SETENV} ${CONFIGURE_ENV} ./configure

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
