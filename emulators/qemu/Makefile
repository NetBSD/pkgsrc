# $NetBSD: Makefile,v 1.64 2010/02/27 23:21:13 tnn Exp $
#

DISTNAME=		qemu-0.12.3
CATEGORIES=		emulators
MASTER_SITES=		http://download.savannah.gnu.org/releases/qemu/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.qemu.org/
COMMENT=		CPU emulator using dynamic translation
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit AND modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		qemu-bin-[0-9]*
NOT_FOR_PLATFORM=	NetBSD-1.[0-6]*-*

USE_TOOLS+=		gmake perl:build
HAS_CONFIGURE=		yes

BUILD_DEPENDS+=		texi2html-[0-9]*:../../textproc/texi2html

# Workaround for PR/41007 - ensure WRKSRC comes before any buildlinked
# directories so we pickup our audio/audio.h. Cannot use CPPFLAGS for this
CFLAGS+=		-I${WRKSRC} -I${WRKSRC}/slirp

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=		mansuffix=/${PKGMANDIR}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX:Q}/share/qemu

.if !empty(MACHINE_PLATFORM:MNetBSD-*)
SUBST_CLASSES+=		lib
SUBST_STAGE.lib=	pre-configure
SUBST_FILES.lib=	x86_64.ld
SUBST_SED.lib=		-e s,/lib64,/lib,g
SUBST_MESSAGE.lib=	fixing hardcoded paths to libraries.
.endif

SUBST_CLASSES+=		snd
SUBST_STAGE.snd=	pre-configure
SUBST_FILES.snd=	audio/ossaudio.c
SUBST_SED.snd=		-e s,/dev/dsp,${DEVOSSAUDIO:Q},g
SUBST_MESSAGE.snd=	Fixing hardcoded audio device.

SUBST_CLASSES+=		smbd
SUBST_STAGE.smbd=	pre-configure
SUBST_FILES.smbd=	vl.c
SUBST_SED.smbd=		-e s,/usr/sbin/smbd,${PREFIX:Q}/sbin/smbd,g
SUBST_MESSAGE.smbd=	Fixing hardcoded paths.

# Avoid clash with system include file:
pre-patch:
	mv ${WRKSRC}/audio/audio.h ${WRKSRC}/audio/qaudio.h

SUBST_CLASSES+=		qaudio
SUBST_STAGE.qaudio=	pre-configure
SUBST_FILES.qaudio=	*.c *.h audio/*.c hw/*.c
SUBST_SED.qaudio=	-e s,audio.h\",qaudio.h\",g
SUBST_MESSAGE.qaudio= 	Fixing audio.h confusion

REPLACE_PERL+=		texi2pod.pl

BUILDLINK_PASSTHRU_DIRS+= /usr/lib
BUILDLINK_PASSTHRU_RPATHDIRS+= /usr/lib

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/qemu

post-install:
	${INSTALL_DATA} ${FILESDIR}/Makefile.multinode-NetBSD \
		${DESTDIR}${PREFIX}/share/doc/qemu/

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
