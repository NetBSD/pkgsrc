# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:47:14 jlam Exp $

DISTNAME=	Canna35b2
PKGNAME=	Canna-dict-3.5.2
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna35/

PATCH_SITES=	http://www.jaist.ac.jp/~fujieda/canna/
PATCHFILES=	Canna35b2-unoff1.patch.gz Canna35b2-unoff2.patch.gz \
		Canna35b2-hack1.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.nec.co.jp/japanese/product/computer/soft/canna/
COMMENT=	Kana-Kanji conversion system (dictionary)

BUILD_DEPENDS+=	Canna-server-bin>=3.5.2nb2:../canna-server-bin

FILESDIR=	${.CURDIR}/../canna-lib/files
DISTINFO_FILE=	${.CURDIR}/../canna-lib/distinfo
PATCHDIR=	${.CURDIR}/../canna-lib/patches

BUILD_DEFS+=	USE_INET6
#USE_X11BASE=	yes

.include "../../mk/bsd.prefs.mk"
NO_MTREE=	yes
LOCALBASE=	${IMDICTDIR}
.if 0	# ${USE_INET6} == "YES"
INET6=		-DINET6
.else
INET6=		# empty
.endif
CANNAOWNER?=	daemon
CANNAGROUP?=	daemon
MAKE_ENV+=	CANNAOWNER=${CANNAOWNER} CANNAGROUP=${CANNAGROUP} \
		IMDICTDIR=${IMDICTDIR} INET6=${INET6}

EVAL_PREFIX+=	CANNASERVERBINDIR=Canna-server-bin
.for cmd in MERGE FORCPP FORSORT SPLITWORD MERGEWORD CRXGRAM CRXDIC CRFREQ KPDIC
CANNA_CMD_SED_SCRIPT+=-e 's|\(${cmd} = \).*/\(.*\)|\1${CANNASERVERBINDIR}/bin/\2|'
.endfor

post-patch:
	@${MV} ${WRKSRC}/Canna.conf ${WRKSRC}/Canna.conf.orig
	@${SED} -e 's|\(DicDir.*=\).*|\1${IMDICTDIR}/canna|' \
		${WRKSRC}/Canna.conf.orig > ${WRKSRC}/Canna.conf
	@for file in `${FIND} ${WRKSRC}/dic/ideo -name Imakefile`; do \
		${MV} $$file $$file.orig;	\
		${SED} ${CANNA_CMD_SED_SCRIPT} $$file.orig > $$file;	\
	 done

do-configure:
	@(cd ${WRKSRC}/dic/ideo; ${XMKMF})

do-build:
	@(cd ${WRKSRC}/dic/ideo; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM})

post-build:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/canna \
		> ${WRKDIR}/canna

do-install:
	@(cd ${WRKSRC}/dic/ideo; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install)

.include "../../devel/nbitools/nbitools.mk"
.include "../../mk/bsd.pkg.mk"
