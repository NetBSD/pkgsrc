# $NetBSD: Makefile,v 1.15 2002/04/08 14:44:30 uebayasi Exp $

DISTNAME=	Canna35b2
PKGNAME=	Canna-server-3.5.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna35/

PATCH_SITES=	http://www.jaist.ac.jp/~fujieda/canna/
PATCHFILES=	Canna35b2-unoff1.patch.gz Canna35b2-unoff2.patch.gz \
		Canna35b2-hack1.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.nec.co.jp/japanese/product/computer/soft/canna/
COMMENT=	Kana-Kanji conversion system (server)

DEPENDS+=	Canna-lib>=3.5.2:../../japanese/canna-lib

FILESDIR=	${.CURDIR}/../../japanese/canna-lib/files
DISTINFO_FILE=	${.CURDIR}/../../japanese/canna-lib/distinfo
PATCHDIR=	${.CURDIR}/../../japanese/canna-lib/patches

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"
.if 0	# ${USE_INET6} == "YES"
INET6=		-DINET6
.else
INET6=		# empty
.endif
CANNAOWNER?=	daemon
CANNAGROUP?=	daemon
CANNA_SPOOL=	/var/spool/canna
CANNA_MODE=	0755
DICT_DIR?=	/var/dict
MAKE_ENV+=	CANNAOWNER=${CANNAOWNER} CANNAGROUP=${CANNAGROUP} \
		CANNA_SPOOL=${CANNA_SPOOL} DICT_DIR=${DICT_DIR} INET6=${INET6}
PLIST_SUBST=	CANNAOWNER=${CANNAOWNER} CANNAGROUP=${CANNAGROUP} \
		CANNA_SPOOL=${CANNA_SPOOL} CANNA_MODE=${CANNA_MODE} \
		DICT_DIR=${DICT_DIR} PREFIX=${PREFIX}

INSTALL_TARGET=	instserver instclient

post-patch:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = .*\) misc\(.*\)|\1\2|' \
		-e 's|\(SERVERDIR = .*\) dic/phono\(.*\)|\1\2|' \
		-e 's|\(CLIENTDIR = .*\) dic/phono misc|\1|' \
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile
	@${FIND} ${WRKSRC} -name Imakefile -print | \
	while read f; do \
		${CP} $$f $${f}.orig; \
		( \     
			${ECHO} '/#include ".*\/Canna.conf"$$/a\'; \
			${ECHO} '#include "${FILESDIR}/LinkFileList.rules"'; \
		) | ${SED} -f /dev/stdin $${f}.orig >$$f; \
	done


do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF})

post-build:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/canna \
		> ${WRKDIR}/canna

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
	@${INSTALL_SCRIPT} ${WRKDIR}/canna ${PREFIX}/etc/rc.d/canna
	@${INSTALL_DATA_DIR} ${CANNA_SPOOL}
	@${CHMOD} ${CANNA_MODE} ${CANNA_SPOOL}
	@${CHOWN} ${CANNAOWNER}:${CANNAGROUP} ${CANNA_SPOOL}

.include "../../mk/bsd.pkg.mk"
