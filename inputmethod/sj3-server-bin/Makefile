# $NetBSD: Makefile,v 1.4 2003/07/29 21:35:46 jmmv Exp $
#

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-server-bin-2.0.1.20
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Japanese input method (server binary)

FILESDIR=	${.CURDIR}/../sj3-lib/files
DISTINFO_FILE=	${.CURDIR}/../sj3-lib/distinfo
PATCHDIR=	${.CURDIR}/../sj3-lib/patches

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	SJ3OWNER SJ3GROUP
SJ3OWNER?=	daemon
SJ3GROUP?=	daemon
MAKE_ENV+=	SJ3OWNER=${SJ3OWNER} SJ3GROUP=${SJ3GROUP} \
		IMDICTDIR=${IMDICTDIR} LOCAL_LDFLAGS="${LDFLAGS}"

RCD_SCRIPTS=		sj3

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
	@${ECHO} '#!${RCD_SCRIPTS_SHELL}'		 > ${WRKDIR}/sj3
	@${ECHO} 'sj3=${PREFIX}/bin/sj3serv'		>> ${WRKDIR}/sj3
	@${ECHO} 'if [ -f $$sj3 ]; then'		>> ${WRKDIR}/sj3
	@${ECHO} "    echo -n ' sj3'"			>> ${WRKDIR}/sj3
	@${ECHO} '	$$sj3'				>> ${WRKDIR}/sj3
	@${ECHO} 'fi'					>> ${WRKDIR}/sj3

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/sj3 ${PREFIX}/etc/rc.d/sj3

.include "../../devel/nbitools/nbitools.mk"
.include "../../inputmethod/sj3-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
