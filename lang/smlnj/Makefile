# $NetBSD: Makefile,v 1.35 2019/10/12 20:52:53 he Exp $
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
PKGREVISION=	3

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	smlnj-${SML_VERSION}
USE_TOOLS+=	gmake pax

# previous versions of the package had an additional '-'
CONFLICTS=	sml-nj-[0-9]*

SML_BASE=	${PREFIX}/lib/smlnj
SML_LIBDIR=	${SML_BASE}/lib
SML_BINDIR=	${SML_BASE}/bin
SML_SCRIPTS=	_link-sml _run-sml _ml-build _ml-makedepend

# while building, the work directory is the "installation"
BUILD_ENV+=	SMLNJ_HOME="${WRKDIR}"

# the build uses patch directly (yuk)
BUILD_ENV+=	PATCH=${PATCH:Q} PATCH_ARGS=${PATCH_ARGS:Q}

# useful for debugging
#CFLAGS+=	-Wall

# note that this includes bsd.prefs.mk
.include "../../lang/smlnj/Makefile.common"

BOXES= x86 ppc sparc

.if make(distinfo) || make(makesum) || make(mdi)
.for B in ${BOXES}
DISTFILES+=    boot.${B}-unix.tgz
.endfor
.endif

#
# For smlnj reasons the runtime system needs to be unpacked twice, once
# in work/src and once in work/base.
#
# As of 20160624, instead of inconsistently patching one copy or the
# other and hoping, or patching both and duplicating all the patches,
# we'll patch only work/src, and then *after* patching clone work/src
# into work/base.
#

# create parent directories for the runtime system
pre-extract:
	${MKDIR} ${WRKDIR}/src || ${TRUE}
	${MKDIR} ${WRKDIR}/base || ${TRUE}

# make it easier to patch the runtime system
do-extract:
	${RUN} extract_file="${_DISTDIR}/config.tgz";	\
		export extract_file;			\
		cd ${WRKDIR}; ${EXTRACT_CMD}
	${RUN} extract_file="${_DISTDIR}/runtime.tgz";	\
		export extract_file;			\
		cd ${WRKDIR}/src; ${EXTRACT_CMD}

# symlink the rest of the distfiles
# also copy in new configs 
post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/* .
	cp ${FILESDIR}/mk.* ${WRKDIR}/src/runtime/objs/

# make the necessary copy of the runtime, _after_ patching src
post-patch:
	cd ${WRKDIR}/src && pax -rw runtime ${WRKDIR}/base/

# Turn of nlffi on powerpc (I guess it doesn't work?)
#
# XXX: this switch doesn't work any more as the line in question doesn't
# exist in the current version. Someone with a PPC build machine,
# please check it out and either change it to match the file if still
# needed, or get rid of it.
.if ${MACHINE_ARCH} == "powerpc"
SUBST_CLASSES+=		nlffi
SUBST_STAGE.nlffi=	pre-configure
SUBST_MESSAGE.nlffi=	Turning off nlffi
SUBST_FILES.nlffi=	config/targets
SUBST_SED.nlffi=	-e '/^request nlffi$$/d'
.endif # powerpc

# resolve definition of SML_BASE
SUBST_CLASSES+=		smlbase
SUBST_STAGE.smlbase=	pre-configure
SUBST_MESSAGE.smlbase=	Setting SML_BASE
SUBST_FILES.smlbase=	${SML_SCRIPTS:S/^/config\//}
SUBST_VARS.smlbase=	SML_BASE

# resolve definition of CFLAGS in patched files
# (note that we need to do this in both src/runtime and base/runtime)
SUBST_CLASSES+=		cflags
SUBST_STAGE.cflags=	pre-configure
SUBST_MESSAGE.cflags=	Setting CFLAGS
SUBST_FILES.cflags=	src/runtime/objs/* base/runtime/objs/*
SUBST_VARS.cflags=	CFLAGS

# use the proper shell
SUBST_CLASSES+=		shell
SUBST_STAGE.shell=	pre-configure
SUBST_MESSAGE.shell=	Choosing the right shell
SUBST_FILES.shell=	config/install.sh
SUBST_VARS.shell=	CONFIG_SHELL

# nothing here any more
do-configure:
	${DO_NADA}

# The build target needs to run $WRKDIR/config/install.sh
do-build:
	cd ${WRKDIR} && unset PWD && ${SETENV} ${BUILD_ENV} \
		${CONFIG_SHELL} ./config/install.sh

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
