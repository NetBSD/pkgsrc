# $NetBSD: Makefile,v 1.9 2005/05/16 01:32:23 jlam Exp $

PKGNAME=		realplayer-8.0.1
PKGREVISION=		2
CATEGORIES=		multimedia
MASTER_SITES=		# empty
EXTRACT_SUFX=		.bin

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
DISTNAME=		rp8_linux20_libc6_i386_cs1
EXTRA_DIST=		rv9_libc6_i386_cs2.tgz
PLIST_SUBST+=		RV9=""
.elif ${MACHINE_ARCH} == "powerpc"
DISTNAME=		rp8_linux_powerpc_cs1
PLIST_SUBST+=		RV9="@comment "
.elif ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
DISTNAME=		rp8_solaris27_sparc_cs2
PLIST_SUBST+=		RV9="@comment "
.else
DISTNAME=		must_be_defined
.endif
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${EXTRA_DIST}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.real.com/products/player/
COMMENT=		RealAudio and RealVideo player

.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "powerpc"
DEPENDS+=		suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=		suse_openmotif>=7.3:../../emulators/${SUSE_DIR_PREFIX}_openmotif
.  elif ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
.    if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON= "${PKGNAME} requires Solaris libraries - see compat_svr4(8)"
.    endif
.  endif
.endif

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-sparc64 NetBSD-*-sparc NetBSD-*-powerpc SunOS-*-sparc

CONFLICTS=		realplayer-codecs<8nb2

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
PKGSRC_USE_TOOLS+=	tar
WRKSRC=			${WRKDIR}/RealPlayer8
CRYPTO=			# defined
INTERACTIVE_STAGE=	fetch extract
CHECK_SHLIBS=		NO

XAUTHORITY?=		${HOME}/.Xauthority
.if exists(${XAUTHORITY})
EXTRACT_CMD=		HOME=${WRKDIR} XAUTHORITY=${XAUTHORITY} ${RP_INSTALLER}
.else
EXTRACT_CMD=		HOME=${WRKDIR} ${RP_INSTALLER}
.endif

DOWNLOAD=		http://forms.real.com/real/player/blackjack.html
RP_INSTALLER=		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
REALPLAYER_HOME=	${PREFIX}/lib/RealPlayer8
NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins
MESSAGE_SUBST+=		REALPLAYER_HOME=${REALPLAYER_HOME}

_FETCH_MESSAGE= \
	    ${ECHO} "==============================================================="; \
	    ${ECHO} "  RealPlayer 8 for Linux 2.x (i386) must be fetched"; \
	    ${ECHO} "  into ${DISTDIR} from"; \
	    ${ECHO} "  ${DOWNLOAD}";
.if defined(EXTRA_DIST)
_FETCH_MESSAGE+= \
	    ${ECHO} "  You also need the file ${EXTRA_DIST} which you can"; \
	    ${ECHO} "  get following the"; \
	    ${ECHO} "  \`\`RV9 Codec packs for Unix RealPlayer 8'' link"; \
	    ${ECHO} "  on the same page.";
.endif
_FETCH_MESSAGE+= \
	    ${ECHO} "==============================================================="

pre-extract:
	@delay=15;							\
	${SED}	-e "s|@WRKSRC@|${WRKSRC}|g"				\
		-e "s|@delay@|$${delay}|g"				\
		${FILESDIR}/extract_instructions;			\
	sleep $${delay}
	@if [ ! -x ${RP_INSTALLER} ]; then				\
		${CHMOD} +x ${RP_INSTALLER};				\
	fi

post-extract:
	if [ "X${EXTRA_DIST}" != "X" ]; then \
		cd ${WRKDIR} && ${TAR} -xzf ${_DISTDIR}/${DISTSUBDIR}/${EXTRA_DIST}; \
	fi

do-build:
	cd ${WRKSRC};							\
		${MV} -f mimeinstall.sh mimeinstall.sh.old;		\
		${SED}	-e "s,@PREFIX@,${PREFIX},g"			\
			-e "s,@REALPLAYER_HOME@,${REALPLAYER_HOME},g"	\
			mimeinstall.sh.old > mimeinstall.sh;		\
		${CHMOD} +x mimeinstall.sh
	${SED}	-e "s,@REALPLAYER_HOME@,${REALPLAYER_HOME},g"		\
		${FILESDIR}/realplay.sh > ${WRKDIR}/realplay.sh

pre-install:
	${FIND} ${WRKSRC} \( -name "*.orig" -o -name "*.old" \) -print	\
		| ${XARGS} ${RM}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/realplay.sh ${PREFIX}/bin/realplay
	cd ${WRKDIR} && ${PAX} -rw RealPlayer8 ${PREFIX}/lib
	if [ "X${EXTRA_DIST}" != "X" ]; then \
		${INSTALL_DATA} ${WRKDIR}/rv9/codecs/drv4.so.6.0 \
			${PREFIX}/lib/RealPlayer8/Codecs/; \
		${INSTALL_DATA} ${WRKDIR}/rv9/codecs/rv40.so.6.0 \
			${PREFIX}/lib/RealPlayer8/Codecs/; \
	fi

post-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${REALPLAYER_HOME}/raclass.zip ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${REALPLAYER_HOME}/rpnp.so ${NS_PLUGINS_DIR}

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386"
.include "../../emulators/suse_linux/Makefile.application"
.endif
.include "../../mk/bsd.pkg.mk"
