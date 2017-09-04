# $NetBSD: Makefile,v 1.25 2017/09/04 18:00:56 wiz Exp $

DISTNAME=	skk9.6
PKGNAME=	skkserv-3.9.4
PKGREVISION=	7
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://skk.kuis.kyoto-u.ac.jp/
COMMENT=	Dictionary server for Simple Kana-Kanji conversion programs
LICENSE=	gnu-gpl-v2

DEPENDS=	skk-jisyo>=200708:../../inputmethod/skk-jisyo

WRKSRC=		${WRKDIR}/skk-9.6

BUILD_DEFS+=	IPV6_READY

DIST_SUBDIR=	skk

GNU_CONFIGURE=	YES
BUILD_DIRS=	skkserv

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS")
.if exists(/usr/ccs)
SKKSERV_UID?=	60002		# noaccess
SKKSERV_GID?=	60002		# noaccess
.else
SKKSERV_UID?=	65534		# nobody
SKKSERV_GID?=	65534		# nogroup
.endif
.endif
SKKSERV_UID?=	32767		# nobody
SKKSERV_GID?=	32766		# nogroup
MAKE_ENV+=	SKKUID=${SKKSERV_UID:Q} SKKGID=${SKKSERV_GID:Q}

RCD_SCRIPTS=	skkserv

SUBST_CLASSES+=		ver-num
SUBST_STAGE.ver-num=	pre-configure
SUBST_MESSAGE.ver-num=	Fixing version number and its comments.
SUBST_FILES.ver-num=	skkserv/skkserv.c
SUBST_SED.ver-num=	-e 's,"${PKGVERSION_NOREV} ","${PKGVERSION} (binary search) ",g'

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

INSTALLATION_DIRS=	share/skk

post-install:
	${INSTALL_DATA} ${WRKSRC}/skkserv/README ${DESTDIR}${PREFIX}/share/skk/README.skkserv

.include "../../mk/bsd.pkg.mk"
