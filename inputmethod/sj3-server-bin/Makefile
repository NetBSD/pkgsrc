# $NetBSD: Makefile,v 1.16 2010/01/09 16:15:41 joerg Exp $
#

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-server-bin-2.0.1.20
PKGREVISION=	6
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	SJ3 Japanese input method server & client

DISTINFO_FILE=	${.CURDIR}/../sj3-lib/distinfo
PATCHDIR=	${.CURDIR}/../sj3-lib/patches

NOT_FOR_PLATFORM+=	${LP64PLATFORMS}

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	itools
USE_IMAKE=	yes
MAKE_ENV+=	SJ3OWNER=${SJ3OWNER:Q} SJ3GROUP=${SJ3GROUP:Q}		\
		IMDICTDIR=${IMDICTDIR:Q} LOCAL_LDFLAGS=${LDFLAGS:M*:Q}

SJ3OWNER?=	daemon
SJ3GROUP?=	daemon

FILES_SUBST+=	IMDICTDIR=${IMDICTDIR:Q}
FILES_SUBST+=	SJ3OWNER=${SJ3OWNER:Q}
FILES_SUBST+=	SJ3GROUP=${SJ3GROUP:Q}

PKG_GROUPS+=	${SJ3GROUP}
PKG_USERS+=	${SJ3OWNER}:${SJ3GROUP}

PKG_GROUPS_VARS+=	SJ3GROUP
PKG_USERS_VARS+=	SJ3USER

MAKE_DIRS+=		${IMDICTDIR}
OWN_DIRS+=		${IMDICTDIR}/sj3
OWN_DIRS_PERMS+=	${IMDICTDIR}/sj3/user ${SJ3OWNER} ${SJ3GROUP} 0755

RCD_SCRIPTS=	sj3

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = .*\)sj3lib \(.*\)|\1\2|'	\
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile
	@${MV} ${WRKSRC}/dict/Imakefile ${WRKSRC}/dict/Imakefile.orig
	@${SED} -e 's|\(SUBDIRS = .*\)dict|\1|'	\
		${WRKSRC}/dict/Imakefile.orig > ${WRKSRC}/dict/Imakefile
	@for file in `${FIND} ${WRKSRC} -name Imakefile -print`; do	\
		${MV} -f $$file $$file.orig;			\
		${SED} -e 's|\(= \).*/lib\(sj3lib\).a|\1-l\2|'	\
			-e 's|^DEPLIBS.*|DEPLIBS =|'		\
			$$file.orig > $$file;			\
	 done

.include "../../inputmethod/sj3-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
