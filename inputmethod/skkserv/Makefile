# $NetBSD: Makefile,v 1.9 2004/04/27 20:51:10 reed Exp $

DISTNAME=	skk9.6
PKGNAME=	skkserv-3.9.4
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

PATCHFILES=	SKK-JISYO.L.diff.gz
PATCH_SITES=	http://www.ht-net21.ne.jp/%7Enaoki-w/skk/
PATCH_DIST_ARGS= -d ${WRKSRC}/jisyo --forward --quiet

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://skk.kuis.kyoto-u.ac.jp/
COMMENT=	Dictionary server for Simple Kana-Kanji conversion programs

WRKSRC=			${WRKDIR}/skk-9.6
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

BUILD_DEFS+=	USE_INET6

DIST_SUBDIR=	skk

GNU_CONFIGURE=	YES

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
MAKE_ENV=	SKKUID=${SKKSERV_UID} SKKGID=${SKKSERV_GID}

# tmp for building dictionary.  ~16MB required.  mfs would be much faster.
TMPDIR?=	${WRKDIR}

RCD_SCRIPTS=	skkserv

post-build:
	:
	: Merging dictionaries....
	:
	${WRKSRC}/jisyo-tools/skkdic-expr -d ${TMPDIR}	\
		${WRKSRC}/jisyo/SKK-JISYO.L + ${WRKSRC}/jisyo/SKK-JISYO.JIS2 | \
	    ${WRKSRC}/jisyo-tools/skkdic-sort >${WRKDIR}/SKK-JISYO.L

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/skk
	${INSTALL_DATA} ${WRKDIR}/SKK-JISYO.L ${PREFIX}/share/skk/SKK-JISYO.L
	${INSTALL_DATA} ${WRKSRC}/skkserv/README ${PREFIX}/share/skk/README.skkserv
	${INSTALL_DATA} ${WRKSRC}/jisyo-tools/README.1st ${PREFIX}/share/skk/README.1st.jisyo-tools
	${INSTALL_DATA} ${WRKSRC}/jisyo-tools/README ${PREFIX}/share/skk/README.jisyo-tools

.include "../../mk/bsd.pkg.mk"
