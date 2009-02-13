# $NetBSD: options.mk,v 1.1 2009/02/13 13:47:18 abs Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.xbeeb
PKG_SUPPORTED_OPTIONS=	mitshm xbeeb-roms
PKG_SUGGESTED_OPTIONS=

# The emulator can be compiled either to use MIT-SHM, or to not.
# Unfortunately it doesn't support both at once.
.if empty(PKG_OPTIONS:Mmitshm)
SUBST_CLASSES+=		nomitshm
SUBST_STAGE.nomitshm=	post-patch
SUBST_MESSAGE.nomitshm=	Disabling MIT-SHM
SUBST_FILES.nomitshm=	src/Config.h
SUBST_SED.nomitshm=	-e "s|\#define	*MITSHM|\#undef MITSHM|"
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		xbeeb-roms

.if !empty(PKG_OPTIONS:Mmitshm)

.include "../../x11/xextproto/buildlink3.mk"

.endif

.if !empty(PKG_OPTIONS:Mxbeeb-roms)
PLIST.xbeeb-roms=	yes
LICENSE=		xbeeb-pseudolicense
RESTRICTED=		No redistribution allowed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

DISTFILES=		${DISTNAME}${EXTRACT_SUFX} OS-1.2.rom BASIC2.rom
SITES.BASIC2.rom= http://bbc.nvg.org/rom/Acorn/lang/
SITES.OS-1.2.rom= http://bbc.nvg.org/rom/Acorn/os/

ROMDIR=${PREFIX}/${XBEEBROOT}/roms
post-install:
	${INSTALL_DATA} ${DISTDIR}/OS-1.2.rom ${DESTDIR}${ROMDIR}/OS1.2.rom
	${INSTALL_DATA} ${DISTDIR}/BASIC2.rom ${DESTDIR}${ROMDIR}/BASIC4.rom

.endif
