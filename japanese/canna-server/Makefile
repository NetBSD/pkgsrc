# $NetBSD: Makefile,v 1.2 1999/08/27 04:06:58 sakamoto Exp $

DISTNAME=	Canna35b2
PKGNAME=	Canna-server-3.5b2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna35/

PATCH_SITES=	http://www.jaist.ac.jp/~fujieda/canna/
PATCHFILES=	Canna35b2-unoff1.patch.gz Canna35b2-unoff2.patch.gz \
		Canna35b2-hack1.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.nec.co.jp/japanese/product/computer/soft/canna/

DEPENDS+=	Canna-lib-3.5b2:../../japanese/canna-lib

MASTERDIR=	${.CURDIR}/../../japanese/canna-lib
FILESDIR=	${MASTERDIR}/files
PATCHDIR=	${MASTERDIR}/patches

.include "../../mk/bsd.prefs.mk"
CANNAOWNER?=	daemon
CANNAGROUP?=	daemon
CANNA_SPOOL=	/var/spool/canna
CANNA_MODE=	0755
DICT_DIR?=	/var/dict
MAKE_ENV+=	CANNAOWNER=${CANNAOWNER} CANNAGROUP=${CANNAGROUP} \
		CANNA_SPOOL=${CANNA_SPOOL} DICT_DIR=${DICT_DIR}

STARTUP_SCRIPT=	etc/rc.d/canna.sh
STARTUP_SCRIPT_SRC=${WRKDIR}/STARTUP

PLIST_TMP=	${PKGDIR}/PLIST
PLIST_SRC=	${WRKDIR}/PLIST

INSTALL_TARGET=	instserver instclient

post-patch:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = .*\) misc\(.*\)|\1\2|' \
		-e 's|\(SERVERDIR = .*\) dic/phono\(.*\)|\1\2|' \
		-e 's|\(CLIENTDIR = .*\) dic/phono misc|\1|' \
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF})

post-build:
	@${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT_SRC}
	@${ECHO} 'canna=${PREFIX}/sbin/cannaserver' >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} 'if [ -f $$canna ]; then' >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} "    echo -n ' Canna'" >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} '     $$canna' >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} "fi" >> ${STARTUP_SCRIPT_SRC}
	@${SED} -e 's|$${CANNAOWNER}|${CANNAOWNER}|'		\
		-e 's|$${CANNAGROUP}|${CANNAGROUP}|'		\
		-e 's|$${CANNA_SPOOL}|${CANNA_SPOOL}|'		\
		-e 's|$${CANNA_MODE}|${CANNA_MODE}|'		\
		-e 's|$${DICT_DIR}|${DICT_DIR}|g'		\
		-e 's|$${PREFIX}|${PREFIX}|'			\
		${PLIST_TMP} > ${PLIST_SRC}

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
	@${INSTALL_SCRIPT} ${STARTUP_SCRIPT_SRC} ${PREFIX}/${STARTUP_SCRIPT}
	@${MKDIR} ${CANNA_SPOOL}
	@${CHMOD} ${CANNA_MODE} ${CANNA_SPOOL}
	@${CHOWN} ${CANNAOWNER}:${CANNAGROUP} ${CANNA_SPOOL}

.include "../../mk/bsd.pkg.mk"
