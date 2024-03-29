# $NetBSD: Makefile,v 1.18 2023/06/06 12:41:37 riastradh Exp $

CANNA_MODULE=	dict

MAKE_JOBS_SAFE=	no

.include "../../inputmethod/canna/Makefile.common"

TOOL_DEPENDS+=	Canna-server>=${CANNA_VERSION}:../../inputmethod/canna-server

.for cmd in MERGE FORCPP FORSORT SPLITWORD MERGEWORD CRXGRAM CRXDIC CRFREQ KPDIC
CANNA_CMD_SED_SCRIPT+=	\
	-e 's|\(${cmd} = \).*/\(.*\)|\1${LOCALBASE}/bin/\2|'
.endfor

DICT_WRKSRC=		${WRKSRC}/dic/ideo
CANNA_DICTDIR=		${PREFIX}/libdata/canna

PKG_GROUPS=	${CANNA_GROUP}
PKG_USERS=	${CANNA_USER}:${CANNA_GROUP}

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	${SED} -e 's|\(SUBDIRS = \).*|\1 canna lib/RKindep dic/ideo|' \
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile
	@${MV} ${WRKSRC}/Canna.conf ${WRKSRC}/Canna.conf.orig
	@${SED} -e 's|\(DicDir.*=\).*|\1${IMDICTDIR}/canna|'		\
		${WRKSRC}/Canna.conf.orig > ${WRKSRC}/Canna.conf
	@for file in `${FIND} ${DICT_WRKSRC} -name Imakefile -print`; do \
		${MV} $$file $$file.orig;				\
		${SED} ${CANNA_CMD_SED_SCRIPT} $$file.orig > $$file;	\
	done

INSTALLATION_DIRS+=	${CANNA_DICTDIR}

do-install:
	${INSTALL_DATA} ${DICT_WRKSRC}/grammar/fuzokugo.cbd		\
					${DESTDIR}${CANNA_DICTDIR}
	${INSTALL_DATA} ${DICT_WRKSRC}/words/bushu.cld			\
					${DESTDIR}${CANNA_DICTDIR}
	${INSTALL_DATA} ${DICT_WRKSRC}/words/dics.dir			\
					${DESTDIR}${CANNA_DICTDIR}
	${INSTALL_DATA} ${DICT_WRKSRC}/words/iroha.cbd			\
					${DESTDIR}${CANNA_DICTDIR}
	${INSTALL_DATA} ${DICT_WRKSRC}/words/iroha.cld 			\
					${DESTDIR}${CANNA_DICTDIR}
	${INSTALL_DATA} ${DICT_WRKSRC}/words/chimei.t			\
					${DESTDIR}${CANNA_DICTDIR}/chimei.ctd
	${INSTALL_DATA} ${DICT_WRKSRC}/words/hojomwd.t			\
					${DESTDIR}${CANNA_DICTDIR}/hojomwd.ctd
	${INSTALL_DATA} ${DICT_WRKSRC}/words/hojoswd.t			\
					${DESTDIR}${CANNA_DICTDIR}/hojoswd.ctd
	${INSTALL_DATA} ${DICT_WRKSRC}/words/kanasmpl.t			\
					${DESTDIR}${CANNA_DICTDIR}/kanasmpl.ctd
	${INSTALL_DATA} ${DICT_WRKSRC}/words/katakana.t			\
					${DESTDIR}${CANNA_DICTDIR}/katakana.ctd
	${INSTALL_DATA} ${DICT_WRKSRC}/words/keishiki.t			\
					${DESTDIR}${CANNA_DICTDIR}/keishiki.ctd
	${INSTALL_DATA} ${DICT_WRKSRC}/words/necgaiji.t			\
					${DESTDIR}${CANNA_DICTDIR}/necgaiji.ctd
	${INSTALL_DATA} ${DICT_WRKSRC}/words/number.t			\
					${DESTDIR}${CANNA_DICTDIR}/number.ctd
	${INSTALL_DATA} ${DICT_WRKSRC}/words/software.t			\
					${DESTDIR}${CANNA_DICTDIR}/software.ctd
	${INSTALL_DATA} ${DICT_WRKSRC}/words/suffix.t			\
					${DESTDIR}${CANNA_DICTDIR}/suffix.ctd

REQD_DIRS_PERMS+=	${CANNA_DICTDIR} ${CANNA_USER} ${CANNA_GROUP} 0775
.for d in fuzokugo.cbd bushu.cld dics.dir iroha.cbd iroha.cld \
	chimei.ctd hojomwd.ctd hojoswd.ctd kanasmpl.ctd katakana.ctd \
	keishiki.ctd necgaiji.ctd number.ctd software.ctd suffix.ctd
SPECIAL_PERMS+=		${CANNA_DICTDIR}/${d} ${CANNA_USER} ${CANNA_GROUP} 0664
.endfor

.include "../../inputmethod/canna-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
