# $NetBSD: Makefile,v 1.8 2020/06/18 10:14:54 micha Exp $

VERS=			1.48.4
PKGNAME=		doomlegacy-${VERS}
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=doomlegacy/}
DISTNAME=		${PKGNAME_NOREV:S/-/_/}_source
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
# Dependency generation fails with parallel build
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
CFLAGS.SunOS+=		-DSOLARIS
LDFLAGS.SunOS+=		-lresolv
.endif

.if ${MACHINE_ENDIAN} == "big"
# Some compilers define this themselves (but maybe not all)
CFLAGS+=		-D__BIG_ENDIAN__
.endif

# Required by extended node patch for ZDoom compressed node format
CFLAGS+=		-DHAVE_ZLIB
LDFLAGS+=		-lz

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 share/doc/doomlegacy ${DOOMWADDIR}

# Honor environment
SUBST_CLASSES+=		makeopt
SUBST_STAGE.makeopt=	do-configure
SUBST_MESSAGE.makeopt=	Preparing make_options file ...
SUBST_FILES.makeopt=	make_options
SUBST_SED.makeopt=	-e 's,\#COMP_ENVIRONMENT,COMP_ENVIRONMENT,'

# Configure defaults for LEGACYWADDIR and DOOMWADDIR
SUBST_CLASSES+=		doomdef
SUBST_STAGE.doomdef=	do-configure
SUBST_MESSAGE.doomdef=	Preparing doomdef.h file ...
SUBST_FILES.doomdef=	src/doomdef.h
SUBST_SED.doomdef=	-e 's,LEGACYWADDIR  "/usr/local/share/games/doomlegacy",LEGACYWADDIR  "${PREFIX}/${DOOMWADDIR}",g'
SUBST_SED.doomdef+=	-e 's,DEFWADS01  "~/games/doomlegacy/wads",DEFWADS01  "${PREFIX}/${DOOMWADDIR}",'

# Process INSTALL.pkgsrc
SUBST_CLASSES+=		install
SUBST_STAGE.install=	do-configure
SUBST_MESSAGE.install=	Preparing INSTALL.pkgsrc file ...
SUBST_FILES.install=	${WRKDIR}/INSTALL.pkgsrc
SUBST_SED.install=	-e 's,DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

pre-configure:
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}
	${CP} ${FILESDIR}/doomlegacy.sh ${WRKDIR}
	${CP} ${FILESDIR}/doomlegacy.6.in ${WRKDIR}
	${CP} ${FILESDIR}/p_blockmap.c ${WRKSRC}/src
	${CP} ${FILESDIR}/p_blockmap.h ${WRKSRC}/src
	${CP} ${FILESDIR}/p_extnodes.c ${WRKSRC}/src
	${CP} ${FILESDIR}/p_extnodes.h ${WRKSRC}/src
	cd ${WRKSRC} && ${CP} make_options_nix make_options

# Process start script and manpage templates
do-configure:
	cd ${WRKDIR} &&							\
		${SED} -e 's,$$PREFIX,${PREFIX},'			\
			doomlegacy.sh >doomlegacy
	cd ${WRKDIR} &&							\
		 ${SED} -e 's,$$NAME,doomlegacy,g'			\
			-e 's,$$VERSION,${VERS},g'			\
			-e 's,$$WADDIR,${PREFIX}/${DOOMWADDIR},g'	\
			doomlegacy.6.in >doomlegacy.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doomlegacy			\
		${DESTDIR}${PREFIX}/bin/doomlegacy.bin
	${INSTALL_SCRIPT} ${WRKDIR}/doomlegacy				\
		${DESTDIR}${PREFIX}/bin/doomlegacy
	${INSTALL_DATA} ${WRKDIR}/doomlegacy_${VERS}/legacy.wad		\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/legacy.wad
	cd ${WRKSRC} &&							\
		${INSTALL_DATA} docs/legacy.css docs/whatsnew.html	\
			${DESTDIR}${PREFIX}/share/doc/doomlegacy
	${INSTALL_DATA} ${WRKDIR}/INSTALL.pkgsrc			\
		${DESTDIR}${PREFIX}/share/doc/doomlegacy/INSTALL.pkgsrc
	${INSTALL_MAN} ${WRKDIR}/doomlegacy.6				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

# Ensure that at least the shareware Episode 1 of Doom is available
DEPENDS+=		doom1-[0-9]*:../../games/doom1

BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.7
.include "../../audio/SDL_mixer/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL+=		SDL>=1.2.10
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
