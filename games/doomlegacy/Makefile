# $NetBSD: Makefile,v 1.3 2020/03/20 11:57:40 nia Exp $

VERS=			1.47.2
PKGNAME=		doomlegacy-${VERS}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=doomlegacy/}
DISTNAME=		${PKGNAME:S/-/_/}_source
DISTFILES=		${DEFAULT_DISTFILES} doomlegacy_${VERS}_common.zip
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		http://doomlegacy.sourceforge.net/
COMMENT=		The legacy of Doom
LICENSE=		gnu-gpl-v2

# Tested on Linux/ppc (32bit Big Endian) and NetBSD/amd64 (64bit Little Endian)
# Untested: In general the source code has support for the other listed OS too
ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-* \
			NetBSD-*-* OpenBSD-*-* SunOS-*-*

USE_LANGUAGES+=		c99

USE_TOOLS+=		gmake
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"
.include "../../mk/endian.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
MAKE_FLAGS+=		OS=FREEBSD
.elif ${OPSYS} == "NetBSD"
MAKE_FLAGS+=		OS=NETBSD
.elif ${OPSYS} == "Darwin"
MAKE_FLAGS+=		OS=MAC
.else
# Other Unix (should work for GNU/Linux, OpenBSD and SunOS)
MAKE_FLAGS+=		OS=LINUX
.endif
MAKE_FLAGS+=		HAVE_MIXER=1

.if ${MACHINE_ENDIAN} == "big"
# Some compilers define this themselves (but maybe not all)
CFLAGS+=		-D__BIG_ENDIAN__
.endif

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/doomlegacy ${DOOMWADDIR}

MESSAGE_SRC+=		MESSAGE.doomlegacy
MESSAGE_SUBST+=		PKGNAME=${PKGNAME:C/-.*//}
MESSAGE_SUBST+=		DOOMWADDIR_CONF="${PREFIX}/${DOOMWADDIR}"

# Configure defaults for LEGACYWADDIR and DOOMWADDIR
SUBST_CLASSES+=		doomdef
SUBST_STAGE.doomdef=	do-configure
SUBST_MESSAGE.doomdef=	Preparing doomdef.h file ...
SUBST_FILES.doomdef=	src/doomdef.h
SUBST_SED.doomdef=	-e 's,LEGACYWADDIR  "/usr/local/share/games/doomlegacy",LEGACYWADDIR  "${PREFIX}/${DOOMWADDIR}",g'
SUBST_SED.doomdef+=	-e 's,DEFWADS01  "~/games/doomlegacy/wads",DEFWADS01  "${PREFIX}/${DOOMWADDIR}",'

pre-configure:
	${CP} ${FILESDIR}/doomlegacy.in1 ${WRKDIR}

# Process manpage template
do-configure:
	cd ${WRKDIR} &&							\
		${SED} -e 's,$$NAME,doomlegacy,g'			\
			-e 's,$$VERSION,${VERS},g'			\
			-e 's,$$WADDIR,${PREFIX}/${DOOMWADDIR},g'	\
			doomlegacy.in1 >doomlegacy.1

do-install:
	cd ${WRKSRC} &&							\
		${INSTALL_PROGRAM} bin/doomlegacy			\
			${DESTDIR}${PREFIX}/bin;			\
		${INSTALL_DATA} docs/legacy.css docs/whatsnew.html	\
			${DESTDIR}${PREFIX}/share/doc/doomlegacy;	\
	cd ${WRKDIR}/doomlegacy_${VERS} &&				\
		${INSTALL_DATA} legacy.wad				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/legacy.wad;	\
	cd ${WRKDIR} &&							\
		${INSTALL_MAN} ${WRKDIR}/doomlegacy.1			\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# Ensure that at least the shareware Episode 1 of Doom is available
# Note: The demos from games/doom1 are not compatible with the Legacy engine
DEPENDS+=		doom1-[0-9]*:../../games/doom1

BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.7
.include "../../audio/SDL_mixer/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL+=		SDL>=1.2.10
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
