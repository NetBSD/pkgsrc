# $NetBSD: Makefile,v 1.1.1.1 1999/12/24 03:19:23 itohy Exp $

DISTNAME=	skk9.6
PKGNAME=	skkserv-3.9.4
WRKSRC=		${WRKDIR}/skk-9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

PATCHFILES=	SKK-JISYO.L.diff.gz
PATCH_SITES=	http://www.ht-net21.ne.jp/%7Enaoki-w/skk/
PATCH_DIST_ARGS= -d ${WRKSRC}/jisyo --forward --quiet

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://skk.kuis.kyoto-u.ac.jp/

DIST_SUBDIR=	skk

GNU_CONFIGURE=	YES
INSTALL_FILE=	${WRKDIR}/INSTALL
MESSAGE_FILE=	${WRKDIR}/MESSAGE

SKKSERV_UID?=	32767
SKKSERV_GID?=	32766
MAKE_ENV=	MAKE_FLAGS='SKKUID=${SKKSERV_UID} SKKGID=${SKKSERV_GID}'

# tmp for building dictionary.  ~16MB required.  mfs would be much faster.
TMPDIR?=	${WRKDIR}

post-build:
	${SED} -e 's#@PREFIX@#${PREFIX}#g' <${FILESDIR}/skkserv.sh	\
		>${WRKDIR}/skkserv.sh
	${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/INSTALL	>${INSTALL_FILE}
	${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/MESSAGE	>${MESSAGE_FILE}
	:
	: Merging dictionaries....
	:
	${WRKSRC}/jisyo-tools/skkdic-expr -d ${TMPDIR}	\
		${WRKSRC}/jisyo/SKK-JISYO.L + ${WRKSRC}/jisyo/SKK-JISYO.JIS2 | \
	    ${WRKSRC}/jisyo-tools/skkdic-sort >${WRKDIR}/SKK-JISYO.L

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/skkserv.sh ${PREFIX}/etc/rc.d
	${MKDIR} ${PREFIX}/share/skk
	${INSTALL_DATA} ${WRKDIR}/SKK-JISYO.L ${PREFIX}/share/skk/SKK-JISYO.L
	${INSTALL_DATA} ${WRKSRC}/skkserv/README ${PREFIX}/share/skk/README.skkserv
	${INSTALL_DATA} ${WRKSRC}/jisyo-tools/README.1st ${PREFIX}/share/skk/README.1st.jisyo-tools
	${INSTALL_DATA} ${WRKSRC}/jisyo-tools/README ${PREFIX}/share/skk/README.jisyo-tools
	${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
