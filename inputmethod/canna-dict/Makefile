# $NetBSD: Makefile,v 1.6 2003/09/23 15:06:59 uebayasi Exp $
#
.include "../canna/Makefile.common"

CANNA_MODULE=	dict

BUILD_DEPENDS+=	Canna-server>=${CANNA_VERSION}:../canna-server

NO_MTREE=	yes
OWN_DIRS=	${PREFIX}/canna

EVAL_PREFIX+=	CANNASERVERBINDIR=Canna-server
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
	@cd ${WRKSRC}/dic/ideo; ${XMKMF}

do-build:
	@cd ${WRKSRC}/dic/ideo; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	@cd ${WRKSRC}/dic/ideo; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install

.include "../canna/Makefile.include"

# Need to set this here _after_ bsd.pkg.mk
PREFIX=		${IMDICTDIR}
