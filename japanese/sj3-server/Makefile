# $NetBSD: Makefile,v 1.3 1999/09/06 07:58:29 sakamoto Exp $
#

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-server-2.0.1.20
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org

DEPENDS+=	sj3-lib-2.0.1.20:../../japanese/sj3-lib

MASTERDIR=	${.CURDIR}/../../japanese/sj3-lib
FILESDIR=	${MASTERDIR}/files
PATCHDIR=	${MASTERDIR}/patches

.include "../../mk/bsd.prefs.mk"
SJ3OWNER?=	daemon
SJ3GROUP?=	daemon
DICT_DIR?=	/var/dict
MAKE_ENV+=	SJ3OWNER=${SJ3OWNER} SJ3GROUP=${SJ3GROUP} DICT_DIR=${DICT_DIR} \
		LOCAL_LDFLAGS="${LDFLAGS}"
PLIST_SUBST=	SJ3OWNER=${SJ3OWNER} SJ3GROUP=${SJ3GROUP} DICT_DIR=${DICT_DIR} \
		PREFIX=${PREFIX}

INSTALL_SRC=	${PKGDIR}/INSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

STARTUP_SCRIPT=	etc/rc.d/sj3.sh
STARTUP_SCRIPT_SRC=${WRKDIR}/STARTUP

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = .*\)sj3lib \(.*\)|\1\2|'	\
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile
	@for file in `find ${WRKSRC} -name Imakefile`; do	\
		${MV} -f $$file $$file.orig;			\
		${SED} -e 's|\(= \).*/lib\(sj3lib\).a|\1-l\2|'	\
			$$file.orig > $$file;			\
	 done

do-configure:
	@(cd ${WRKSRC}; xmkmf; ${MAKE} Makefiles)

post-build:
	@${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT_SRC}
	@${ECHO} 'sj3=${PREFIX}/bin/sj3serv' >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} 'if [ -f $$sj3 ]; then' >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} "    echo -n ' sj3'" >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} '	$$sj3' >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} 'fi' >> ${STARTUP_SCRIPT_SRC}
	@${SED} -e 's|$${SJ3OWNER}|${SJ3OWNER}|'	\
		-e 's|$${SJ3GROUP}|${SJ3GROUP}|'	\
		-e 's|$${DICT_DIR}|${DICT_DIR}|'	\
		-e 's|$${PREFIX}|${PREFIX}|'		\
		${INSTALL_SRC} > ${INSTALL_FILE}

post-install:
	@${INSTALL_SCRIPT} ${STARTUP_SCRIPT_SRC} ${PREFIX}/${STARTUP_SCRIPT}

.include "../../mk/bsd.pkg.mk"
