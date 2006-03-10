# $NetBSD: Makefile,v 1.11 2006/03/10 22:29:44 jlam Exp $
#

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-dict-2.0.1.20
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Japanese input method (dictionary)

BUILD_DEPENDS+=	sj3-server-bin>=2.0.1.20nb1:../../inputmethod/sj3-server-bin

FILESDIR=	${.CURDIR}/../sj3-lib/files
DISTINFO_FILE=	${.CURDIR}/../sj3-lib/distinfo
PATCHDIR=	${.CURDIR}/../sj3-lib/patches

PKG_INSTALLATION_TYPES=	overwrite pkgviews


.include "../../mk/bsd.prefs.mk"

NO_MTREE=       YES
SJ3OWNER?=	daemon
SJ3GROUP?=	daemon
MAKE_ENV+=	SJ3OWNER=${SJ3OWNER:Q} SJ3GROUP=${SJ3GROUP:Q} \
		IMDICTDIR=${IMDICTDIR:Q} LOCAL_LDFLAGS=${LDFLAGS:M*:Q}
FILES_SUBST+=	SJ3OWNER=${SJ3OWNER} SJ3GROUP=${SJ3GROUP} IMDICTDIR=${IMDICTDIR}
INSTALL_SRC=	${PKGDIR}/INSTALL
DEINSTALL_SRC=	# empty

EVAL_PREFIX+=	SJ3SERVERBINDIR=sj3-server-bin

pre-configure:
	@${CHMOD} +w ${WRKSRC}/dict/dict/Imakefile*
	@${MV} ${WRKSRC}/dict/dict/Imakefile ${WRKSRC}/dict/dict/Imakefile.orig
	@${SED} -e 's|$$(TOOL_DIR)/|${SJ3SERVERBINDIR}/bin/|' \
		${WRKSRC}/dict/dict/Imakefile.orig \
			> ${WRKSRC}/dict/dict/Imakefile

do-configure:
	@(cd ${WRKSRC}/dict/dict; ${XMKMF_CMD}; \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} Makefiles)

do-build:
	@(cd ${WRKSRC}/dict/dict; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM})

do-install:
	@(cd ${WRKSRC}/dict/dict; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install)

.include "../../devel/nbitools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# Need to set this here _after_ bsd.pkg.mk
PREFIX=		${IMDICTDIR}
