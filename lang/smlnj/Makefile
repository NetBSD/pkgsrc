# $NetBSD: Makefile,v 1.24 2012/10/02 20:11:53 asau Exp $
#

DISTNAME=	boot.${BOX}-unix
PKGNAME=	smlnj-${SML_VERSION}
CATEGORIES=	lang
MASTER_SITES=	http://smlnj.cs.uchicago.edu/dist/working/${SML_VERSION}/
DISTFILES=	MLRISC.tgz			\
		boot.${BOX}-unix.tgz		\
		ckit.tgz			\
		cm.tgz				\
		cml.tgz				\
		compiler.tgz			\
		config.tgz			\
		eXene.tgz			\
		ml-burg.tgz			\
		ml-lex.tgz			\
		nlffi.tgz			\
		ml-yacc.tgz			\
		runtime.tgz			\
		smlnj-lib.tgz			\
		system.tgz			\
		ml-lpt.tgz			\
		pgraph.tgz			\
		trace-debug-profile.tgz		\
		heap2asm.tgz			\
		smlnj-c.tgz

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://www.smlnj.org/index.html
COMMENT=	Popular functional language from Bell Labs

SML_VERSION=	110.73

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	smlnj-${SML_VERSION}
USE_TOOLS+=	gmake pax

# previous versions of the package had an additional '-'
CONFLICTS=	sml-nj-[0-9]*

SML_BASE=	${PREFIX}/lib/smlnj
SML_LIBDIR=	${SML_BASE}/lib
SML_BINDIR=	${SML_BASE}/bin
SML_SCRIPTS=	_link-sml _run-sml _ml-build _ml-makedepend

.include "../../lang/smlnj/Makefile.common"

# create parent directory for the runtime system
pre-extract:
	${MKDIR} ${WRKDIR}/src || ${TRUE}

# make it easier to patch the runtime system
do-extract:
	${RUN} extract_file="${_DISTDIR}/config.tgz"; export extract_file;	\
		cd ${WRKDIR}; ${EXTRACT_CMD}
	${RUN} extract_file="${_DISTDIR}/runtime.tgz"; export extract_file;	\
		cd ${WRKDIR}/src; ${EXTRACT_CMD}
	${RUN} extract_file="${_DISTDIR}/runtime.tgz"; export extract_file;	\
		mkdir ${WRKDIR}/base; cd ${WRKDIR}/base; ${EXTRACT_CMD}

# make symlinks to the dist files
post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/*  .

# resolve definition of SML_BASE, CFLAGS in patched files
do-configure:
	if [ ${MACHINE_ARCH} = "powerpc" ]; then		\
		${AWK} '(! /^request nlffi$$/) { print }' \
		< ${WRKDIR}/config/targets			\
		> ${WRKDIR}/temp;				\
		${MV} ${WRKDIR}/temp ${WRKDIR}/config/targets;	\
	fi
	cd ${WRKDIR}/config;				\
	for f in ${SML_SCRIPTS}; do			\
		${CP} "$${f}" "$${f}.tmp";		\
		${SED} -e 's|@SML_BASE@|${SML_BASE}|g'	\
			< "$${f}.tmp" > "$${f}";	\
	done;						\
	cd ${WRKDIR}/src/runtime/objs;			\
	for f in *; do					\
		${CP} "$${f}" "$${f}.tmp";		\
		${SED} -e 's|@CFLAGS@|${CFLAGS}|g'	\
			< "$${f}.tmp" > "$${f}";	\
	done

# The build target needs to run $WRKDIR/config/install.sh
do-build:
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="${PATCH_ARGS}" \
		SMLNJ_HOME="${WRKDIR}" ./config/install.sh

# install target
# (see ftp://ftp.research.bell-labs.com/dist/smlnj/working/110.38/INSTALL)
# 1. create installation directories
# 2. copy the ./bin and ./lib directories across
# 3. install links to executables in $PREFIX/bin
INSTALLATION_DIRS=	bin
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${SML_BASE}
	cd ${WRKDIR} && pax -rw -pam bin lib ${DESTDIR}${SML_BASE}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf ../lib/smlnj/bin/* .

.include "../../mk/bsd.pkg.mk"
