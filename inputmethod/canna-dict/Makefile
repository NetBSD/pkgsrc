# $NetBSD: Makefile,v 1.3 2002/12/27 08:41:23 uebayasi Exp $

DISTNAME=	Canna36p1
PKGNAME=	Canna-dict-3.6.1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://downloads.sourceforge.jp/canna/1722/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://canna.sourceforge.jp/
COMMENT=	Kana-Kanji conversion system (dictionary)

BUILD_DEPENDS+=	Canna-server-bin>=3.6.1:../canna-server-bin

FILESDIR=	${.CURDIR}/../canna-lib/files
DISTINFO_FILE=	${.CURDIR}/../canna-lib/distinfo
PATCHDIR=	${.CURDIR}/../canna-lib/patches

BUILD_DEFS+=	USE_INET6
#USE_X11BASE=	yes

.include "../../mk/bsd.prefs.mk"
NO_MTREE=	yes
LOCALBASE=	${IMDICTDIR}
.if 0	# defined(USE_INET6) && ${USE_INET6} == "YES"
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
