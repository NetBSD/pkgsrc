# $NetBSD: Makefile,v 1.11 2009/01/10 03:06:34 obache Exp $

PKGREVISION=	1
CANNA_MODULE=	dict

MAKE_JOBS_SAFE=	no

.include "../../inputmethod/canna/Makefile.common"

BUILD_DEPENDS+=	Canna-server>=${CANNA_VERSION}:../../inputmethod/canna-server

EVAL_PREFIX+=	CANNASERVERBINDIR=Canna-server
.for cmd in MERGE FORCPP FORSORT SPLITWORD MERGEWORD CRXGRAM CRXDIC CRFREQ KPDIC
CANNA_CMD_SED_SCRIPT+=	\
	-e 's|\(${cmd} = \).*/\(.*\)|\1${CANNASERVERBINDIR}/bin/\2|'
.endfor

CONFIGURE_DIRS=		${DICT_WRKSRC}
DICT_WRKSRC=		${WRKSRC}/dic/ideo
CANNA_DICTDIR=		${PREFIX}/libdata/canna

PKG_GROUPS=	${CANNA_GROUP}
PKG_USERS=	${CANNA_USER}:${CANNA_GROUP}

INSTALL_DICT_DIR=	\
	${INSTALL} -d -o ${CANNA_USER} -g ${CANNA_GROUP} -m 0775
INSTALL_DICT=		\
	${INSTALL} ${COPY} -o ${CANNA_USER} -g ${CANNA_GROUP} -m 0664

post-patch:
	@${MV} ${WRKSRC}/Canna.conf ${WRKSRC}/Canna.conf.orig
	@${SED} -e 's|\(DicDir.*=\).*|\1${IMDICTDIR}/canna|'		\
		${WRKSRC}/Canna.conf.orig > ${WRKSRC}/Canna.conf
	@for file in `${FIND} ${WRKSRC}/dic/ideo -name Imakefile -print`; do \
		${MV} $$file $$file.orig;				\
		${SED} ${CANNA_CMD_SED_SCRIPT} $$file.orig > $$file;	\
	done

do-install:
	${INSTALL_DICT_DIR} ${CANNA_DICTDIR}
	${INSTALL_DICT} ${DICT_WRKSRC}/grammar/fuzokugo.cbd ${CANNA_DICTDIR}
	${INSTALL_DICT} ${DICT_WRKSRC}/words/bushu.cld ${CANNA_DICTDIR}
	${INSTALL_DICT} ${DICT_WRKSRC}/words/dics.dir ${CANNA_DICTDIR}
	${INSTALL_DICT} ${DICT_WRKSRC}/words/iroha.cbd ${CANNA_DICTDIR}
	${INSTALL_DICT} ${DICT_WRKSRC}/words/iroha.cld ${CANNA_DICTDIR}

	${INSTALL_DICT} ${DICT_WRKSRC}/words/chimei.t			\
						${CANNA_DICTDIR}/chimei.ctd
	${INSTALL_DICT} ${DICT_WRKSRC}/words/hojomwd.t			\
						${CANNA_DICTDIR}/hojomwd.ctd
	${INSTALL_DICT} ${DICT_WRKSRC}/words/hojoswd.t			\
						${CANNA_DICTDIR}/hojoswd.ctd
	${INSTALL_DICT} ${DICT_WRKSRC}/words/kanasmpl.t			\
						${CANNA_DICTDIR}/kanasmpl.ctd
	${INSTALL_DICT} ${DICT_WRKSRC}/words/katakana.t			\
						${CANNA_DICTDIR}/katakana.ctd
	${INSTALL_DICT} ${DICT_WRKSRC}/words/keishiki.t			\
						${CANNA_DICTDIR}/keishiki.ctd
	${INSTALL_DICT} ${DICT_WRKSRC}/words/necgaiji.t			\
						${CANNA_DICTDIR}/necgaiji.ctd
	${INSTALL_DICT} ${DICT_WRKSRC}/words/number.t			\
						${CANNA_DICTDIR}/number.ctd
	${INSTALL_DICT} ${DICT_WRKSRC}/words/software.t			\
						${CANNA_DICTDIR}/software.ctd
	${INSTALL_DICT} ${DICT_WRKSRC}/words/suffix.t			\
						${CANNA_DICTDIR}/suffix.ctd

.include "../../mk/bsd.pkg.mk"
