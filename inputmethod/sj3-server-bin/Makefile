# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:48:04 jlam Exp $
#

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-server-bin-2.0.1.20
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	Japanese input method (server binary)

FILESDIR=	${.CURDIR}/../sj3-lib/files
DISTINFO_FILE=	${.CURDIR}/../sj3-lib/distinfo
PATCHDIR=	${.CURDIR}/../sj3-lib/patches

.include "../../mk/bsd.prefs.mk"
SJ3OWNER?=	daemon
SJ3GROUP?=	daemon
MAKE_ENV+=	SJ3OWNER=${SJ3OWNER} SJ3GROUP=${SJ3GROUP} \
		IMDICTDIR=${IMDICTDIR} LOCAL_LDFLAGS="${LDFLAGS}"

STARTUP_SCRIPT=	etc/rc.d/sj3
STARTUP_SCRIPT_SRC=${WRKDIR}/STARTUP

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = .*\)sj3lib \(.*\)|\1\2|'	\
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile
	@${MV} ${WRKSRC}/dict/Imakefile ${WRKSRC}/dict/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = .*\)dict|\1|'	\
		${WRKSRC}/dict/Imakefile.orig > ${WRKSRC}/dict/Imakefile
	@for file in `${FIND} ${WRKSRC} -name Imakefile`; do	\
		${MV} -f $$file $$file.orig;			\
		${SED} -e 's|\(= \).*/lib\(sj3lib\).a|\1-l\2|'	\
			$$file.orig > $$file;			\
	 done

do-configure:
	@(cd ${WRKSRC}; ${XMKMF_CMD}; ${MAKE} Makefiles)

post-build:
	@${ECHO} '#!/bin/sh'				 > ${STARTUP_SCRIPT_SRC}
	@${ECHO} 'sj3=${PREFIX}/bin/sj3serv'		>> ${STARTUP_SCRIPT_SRC}
	@${ECHO} 'if [ -f $$sj3 ]; then'		>> ${STARTUP_SCRIPT_SRC}
	@${ECHO} "    echo -n ' sj3'"			>> ${STARTUP_SCRIPT_SRC}
	@${ECHO} '	$$sj3'				>> ${STARTUP_SCRIPT_SRC}
	@${ECHO} 'fi'					>> ${STARTUP_SCRIPT_SRC}

post-install:
	@${INSTALL_SCRIPT} ${STARTUP_SCRIPT_SRC} ${PREFIX}/${STARTUP_SCRIPT}

.include "../../devel/nbitools/nbitools.mk"
.include "../sj3-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
