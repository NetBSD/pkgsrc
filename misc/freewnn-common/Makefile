# $NetBSD: Makefile,v 1.2 1999/08/27 04:36:32 sakamoto Exp $
#

DISTNAME=	FreeWnn-1.10
MASTER_SITES=	ftp://ftp.freewnn.org/pub/FreeWnn/	\
		ftp://etlport.etl.go.jp/pub/FreeWnn/	\
		ftp://ftp.st.ryukoku.ac.jp/pub/japanese-im/FreeWnn/	\
		ftp://ftp.kddlabs.co.jp/Japan/Wnn/FreeWnn/	\
		ftp://ftp.tomo.gr.jp/pub/FreeWnn/

.if !defined(PKGNAME)
IGNORE=		"is FreeWnn base package. Use freewnn-lib/server packages"
.endif

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.freewnn.org/

INSTALL_TARGET=	install install.man

.if defined(WNN_TARGET) && (${WNN_TARGET} == "SERVER")
.include "../../mk/bsd.prefs.mk"
MAKE_ENV+=	"WNN_TARGET=SERVER"
WNNOWNER?=	wnn
DICT_DIR?=	/var/dict
SEDSCRIPT+=	-e 's|\(WNNOWNER = \).*|\1${WNNOWNER}|'
SEDSCRIPT+=	-e 's|([CK]*WNNJLIBSRC)/\(lib[ck]*wnn.a\)|{PREFIX}/lib/\1|'
SEDSCRIPT+=	-e 's|\([JCKT]*WNNDICDIR = \).*|\1${DICT_DIR}/wnn/ja_JP|'
INSTALL_FILE=	${WRKDIR}/INSTALL
INSTALL_SRC=	${FILESDIR}/INSTALL
PLIST_TMP=	${PKGDIR}/PLIST
PLIST_SRC=	${WRKDIR}/PLIST
STARTUP_SCRIPT_SRC=${WRKDIR}/STARTUP
.else
MAKE_ENV+=	"WNN_TARGET=LIBRARY"
.endif

.if defined(WNNDIR)
MAKE_ENV+=	"WNNDIR=${WNNDIR}"
.endif
.if defined(CWNNDIR)
MAKE_ENV+=	"CWNNDIR=${CWNNDIR}"
.endif
.if defined(KWNNDIR)
MAKE_ENV+=	"KWNNDIR=${KWNNDIR}"
.endif

GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/Xsi

post-patch:
	@for file in `find ${WRKSRC} -name Makefile.in`; do	\
		${MV} $$file $$file.orig;			\
		${SED} -e '/PREFIX = /d'			\
			-e 's|\(WNNBINDIR = $${PREFIX}/\)\(bin\)|\1s\2|' \
			-e 's|\([CK]*WNNBINDIR = $$(WNNBINDIR)\)/[ck]*Wnn4|\1|'\
			-e 's|\(WNNWNNDIR = $${PREFIX}/\)lib\(/wnn\)|\1share\2|'\
			-e '/(COMPRESSMANCMD) /d'		\
			-e 's|\/usr\/X11R6|$${PREFIX}|'		\
			${SEDSCRIPT}				\
			$$file.orig > $$file;			\
	done
	@for file in `find ${WRKSRC}/Wnn/man -name Makefile.in`; do	\
		${MV} $$file $$file.orig2;				\
		${SED} -e 's|\(MANPATH = .*\)|\1/ja_JP.EUC|'		\
			$$file.orig2 > $$file;				\
	done

.if defined(WNN_TARGET) && (${WNN_TARGET} == "SERVER")
post-build:
	@${SED} -e 's|$${WNNOWNER}|${WNNOWNER}|g'	\
		${INSTALL_SRC} > ${INSTALL_FILE}
	@${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT_SRC}
	@${ECHO} 'freewnn=${JSERVER}' >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} 'if [ -f $$freewnn ]; then' >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} "    echo -n ' ${SCTITLE}'" >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} '     $$freewnn' >> ${STARTUP_SCRIPT_SRC}
	@${ECHO} "fi" >> ${STARTUP_SCRIPT_SRC}
	@${SED} -e 's|$${DICT_DIR}|${DICT_DIR}|'		\
		-e 's|$${PREFIX}|${PREFIX}|'			\
		${PLIST_TMP} > ${PLIST_SRC}
	@${ECHO} ${STARTUP_SCRIPT} >> ${PLIST_SRC}

pre-install:
	@${SETENV} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} ${STARTUP_SCRIPT_SRC} ${PREFIX}/${STARTUP_SCRIPT}
.endif

.include "../../mk/bsd.pkg.mk"
