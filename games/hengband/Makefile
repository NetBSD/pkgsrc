# $NetBSD: Makefile,v 1.7 2024/05/06 08:40:25 jperkin Exp $

DISTNAME=	hengband-2.2.1r
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_OSDN:=hengband/72520/}

# The tarball for this version is generated without a top-level
# directory.
EXTRACT_DIR=	${WRKSRC}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://hengband.sourceforge.jp/en/index.html
COMMENT=	Rogue-like game derived from Zangband
LICENSE=	gnu-gpl-v2

# Optional 16x16 (large) tile set, only useful for the X11 UI.
HENGBAND_TILE16=		heng-graf-16x16.tar.gz
DISTFILES=			${DEFAULT_DISTFILES} ${HENGBAND_TILE16}
SITES.${HENGBAND_TILE16}=	${MASTER_SITE_OSDN:=hengband/5195/}
EXTRACT_DIR.${HENGBAND_TILE16}=	${WRKSRC}/lib/xtra/graf

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-setgid=${HENGBAND_GROUP}
CONFIGURE_ARGS+=	--with-libpath=${HENGBAND_LIBDIR}/

LDFLAGS.SunOS+=		-lsocket -lnsl

HENGBAND_LIBDIR=	${PREFIX}/libdata/${PKGBASE}
HENGBAND_VARDIR=	${VARBASE}/games/${PKGBASE}
HENGBAND_USER=		${GAMES_USER}
HENGBAND_GROUP=		${GAMES_GROUP}
BUILD_DEFS+=		VARBASE GAMES_USER GAMES_GROUP

SUBST_CLASSES+=		vardir
SUBST_STAGE.vardir=	pre-configure
SUBST_FILES.vardir=	src/init2.c
SUBST_VARS.vardir=	HENGBAND_VARDIR

SPECIAL_PERMS+=		${PREFIX}/bin/hengband \
			${HENGBAND_USER} ${HENGBAND_GROUP} 2555

USE_TOOLS+=	automake autoreconf
pre-configure:
	${RUN}cd ${WRKSRC} && autoreconf -i

# Special handling for the score, save, and pref files: we do not want
# to delete them between package installations and deinstallations.
# See "readme_angband" for the details of these directories.
REQD_DIRS_PERMS+=	${HENGBAND_VARDIR} \
			${HENGBAND_USER} ${HENGBAND_GROUP} 775
REQD_DIRS_PERMS+=	${HENGBAND_VARDIR}/apex \
			${HENGBAND_USER} ${HENGBAND_GROUP} 775
REQD_DIRS_PERMS+=	${HENGBAND_VARDIR}/bone \
			${HENGBAND_USER} ${HENGBAND_GROUP} 775
REQD_DIRS_PERMS+=	${HENGBAND_VARDIR}/data \
			${HENGBAND_USER} ${HENGBAND_GROUP} 775
REQD_DIRS_PERMS+=	${HENGBAND_VARDIR}/save \
			${HENGBAND_USER} ${HENGBAND_GROUP} 775

INSTALLATION_DIRS+=	share/doc/${PKGBASE}
post-install:
	${RUN}for f in autopick.txt autopick_eng.txt readme.txt \
			readme_angband readme_eng.txt; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} \
			${DESTDIR}${PREFIX}/share/doc/${PKGBASE}; \
	done

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
