# $NetBSD: Makefile,v 1.14 2001/09/02 23:04:23 kristerw Exp $
#

DISTNAME=		xmame-0.37b15.2
PKGNAME=		xmess-0.37b15.2
CATEGORIES=		emulators games x11
MASTER_SITES=		http://x.mame.net/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kristerw@netbsd.org
HOMEPAGE=		http://x.mame.net/
COMMENT=		X11 emulator for old computers and console machines

DEPENDS=		unzip>=5.40:../../archivers/unzip

RESTRICTED=		"selling is not allowed"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_X11BASE=		YES
USE_XPM=		YES
USE_GMAKE=		YES
MAKE_ENV+=		OPSYS=${OPSYS} ARCH=${ARCH} \
			MAME_CPU=${MAME_CPU} \
			INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			NETBSD_JOYSTICK="${NETBSD_JOYSTICK}" \
			NETBSD_DGA="${NETBSD_DGA}" \
			DISPLAY_METHOD="${DISPLAY_METHOD}"
MAKEFILE=		makefile.unix
DISPLAY_METHOD= 	x11

ROMPATH=		${PREFIX}/share/xmess
SPOOLDIR=		/var/games/xmess
.if exists(/usr/include/machine/joystick.h)
NETBSD_JOYSTICK=	yes
.else
NETBSD_JOYSTICK=	no
.endif
.if exists(${X11BASE}/include/X11/extensions/xf86dga.h)
NETBSD_DGA=		yes
.else
NETBSD_DGA=		no
.endif

post-patch:
	(cd ${WRKSRC}/doc && ${SED} 's|@ROMPATH@|${ROMPATH}|;s|@SPOOLDIR@|${SPOOLDIR}|' \
		xmamerc.dist >xmessrc)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} xmess.${DISPLAY_METHOD} \
		${PREFIX}/bin/xmess)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} xmess.6 \
		${PREFIX}/man/man6/xmess.6)
	${INSTALL_DATA_DIR} ${ROMPATH}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} xmessrc ${ROMPATH}/xmessrc)
	@${ECHO} Remember to set ROMPATH to ${ROMPATH}.

.include "../../mk/bsd.pkg.mk"

# This has to come after bsd.pkg.mk to make sure we have FILESDIR
.if ${MACHINE_ARCH} == "m68k"
MAME_CPU=		m68k
.elif ${MACHINE_ARCH} == "alpha"
MAME_CPU=		alpha
.elif ${MACHINE_ARCH} == "i386"
MAME_CPU=		i386
.else
# Rather than enumerating all CPU types, check machine/endian.h
ENDIAN!=		${SH} ${FILESDIR}/endian.sh
.if ${ENDIAN} == "LITTLE_ENDIAN"
MAME_CPU=		risc_lsb
.else
MAME_CPU=		risc
.endif
.endif
