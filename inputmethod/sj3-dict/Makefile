# $NetBSD: Makefile,v 1.14 2008/03/04 15:55:14 jlam Exp $
#

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-dict-2.0.1.20
PKGREVISION=	3
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	SJ3 Japanese input method dictionary

BUILD_DEPENDS+=	sj3-server-bin>=2.0.1.20nb1:../../inputmethod/sj3-server-bin

FILESDIR=	${.CURDIR}/../sj3-lib/files
DISTINFO_FILE=	${.CURDIR}/../sj3-lib/distinfo
PATCHDIR=	${.CURDIR}/../sj3-lib/patches

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	itools
USE_IMAKE=	yes
MAKE_ENV+=	SJ3OWNER=${SJ3OWNER:Q} SJ3GROUP=${SJ3GROUP:Q} \
		IMDICTDIR=${IMDICTDIR:Q} LOCAL_LDFLAGS=${LDFLAGS:M*:Q}
FILES_SUBST+=	SJ3OWNER=${SJ3OWNER} SJ3GROUP=${SJ3GROUP} IMDICTDIR=${IMDICTDIR}
EVAL_PREFIX+=	SJ3SERVERBINDIR=sj3-server-bin

CONFIGURE_DIRS+=	dict/dict

SJ3OWNER?=	daemon
SJ3GROUP?=	daemon

INSTALLATION_DIRS=	${PREFIX}/libdata

pre-configure:
	@${CHMOD} +w ${WRKSRC}/dict/dict/Imakefile*
	@${MV} ${WRKSRC}/dict/dict/Imakefile ${WRKSRC}/dict/dict/Imakefile.orig
	@${SED} -e 's|$$(TOOL_DIR)/|${SJ3SERVERBINDIR}/bin/|' \
		${WRKSRC}/dict/dict/Imakefile.orig \
			> ${WRKSRC}/dict/dict/Imakefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/dict/dict/sj3main.dic \
		${DESTDIR}${PREFIX}/libdata

.include "../../mk/bsd.pkg.mk"
