# $NetBSD: Makefile,v 1.12 2005/12/05 20:50:24 rillig Exp $
#

DISTNAME=	sj3-2.0.1.20
PKGNAME=	sj3-server-bin-2.0.1.20
PKGREVISION=	5
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/	\
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Japanese input method (server binary)

DISTINFO_FILE=	${.CURDIR}/../sj3-lib/distinfo
PATCHDIR=	${.CURDIR}/../sj3-lib/patches

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGINSTALL=	YES

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	SJ3OWNER SJ3GROUP
SJ3OWNER?=	daemon
SJ3GROUP?=	daemon
MAKE_ENV+=	SJ3OWNER=${SJ3OWNER:Q} SJ3GROUP=${SJ3GROUP:Q} \
		IMDICTDIR=${IMDICTDIR:Q} LOCAL_LDFLAGS=${LDFLAGS:M*:Q}

RCD_SCRIPTS=		sj3

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

do-configure:
	@(cd ${WRKSRC}; ${XMKMF_CMD}; ${MAKE} Makefiles)

.include "../../devel/nbitools/buildlink3.mk"
.include "../../inputmethod/sj3-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
