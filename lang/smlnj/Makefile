# $NetBSD: Makefile,v 1.1.1.1 2003/03/21 22:20:55 wiz Exp $
#

DISTNAME=	boot.${BOX}-unix
PKGNAME=	smlnj-${SML_VERSION}
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.research.bell-labs.com/dist/smlnj/working/${SML_VERSION}/ \
		ftp://flint.cs.yale.edu/pub/smlnj/working/${SML_VERSION}/
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
		ml-nlffi-lib.tgz		\
		ml-nlffigen.tgz			\
		ml-yacc.tgz			\
		runtime.tgz			\
		smlnj-lib.tgz			\
		system.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cm.bell-labs.com/cm/cs/what/smlnj/index.html
COMMENT=	Popular functional language from Bell Labs

SML_VERSION=	110.41

# smlnj also supports hppa, sparc, ppc, mlrisc & alpha
# pkg support for those platforms, and say, solaris-x86
# is left as an (easy) exercise for the reader.
ONLY_FOR_PLATFORM=	NetBSD-*-i386 SunOS-*-sparc NetBSD-*-sparc

# Other mirror sites that generally carry only released versions of SML
# 	ftp://rodin.stanford.edu/pub/smlnj/release/
# 	ftp://ftp.cl.cam.ac.uk/MIRRORED/smlnj/release/
# 	ftp://ftp.ntua.gr/pub/lang/smlnj/release/

DIST_SUBDIR=	sml-nj-${SML_VERSION}
WRKSRC=		${WRKDIR}
USE_GMAKE=	yes

# previous versions of the package had an additional '-'
CONFLICTS=	sml-nj-[0-9]*

SML_BASE=	${PREFIX}/lib/smlnj
SML_LIBDIR=	${SML_BASE}/lib
SML_BINDIR=	${SML_BASE}/bin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "sparc"
BOX=		sparc
OS=		${LOWER_OPSYS}
.elif ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386"
BOX=		x86
OS=		bsd
.elif ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc"
BOX=		sparc
OS=		bsd
.endif

PLIST_SUBST+=	BOX=${BOX} OS=${OS}

# create parent directory for the runtime system
pre-extract:
	${MKDIR} ${WRKDIR}/src || ${TRUE}

# make it easier to patch the runtime system
do-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extract_file="${_DISTDIR}/config.tgz"; export extract_file;	\
		cd ${WRKDIR}; ${EXTRACT_CMD}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extract_file="${_DISTDIR}/runtime.tgz"; export extract_file;	\
		cd ${WRKDIR}/src; ${EXTRACT_CMD}

# make symlinks to the dist files
post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/*  .

# The build target needs to run $WRKDIR/config/install.sh
do-build:
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="${PATCH_ARGS}" \
		./config/install.sh

# install target
# (see ftp://ftp.research.bell-labs.com/dist/smlnj/working/110.38/INSTALL)
# 1. create installation directories
# 2. copy the ./bin and ./lib directories across
# 3. edit scripts to override BIN_DIR and CM_PATHCONFIG
# 4. install links to executables in $PREFIX/bin
do-install:
	${INSTALL_DATA_DIR} ${SML_BASE}
	(cd ${WRKDIR} && ${PAX} -rw -pam bin lib ${SML_BASE})
.for script in .link-sml .run-sml ml-build ml-makedepend
	${RM} -f ${SML_BINDIR}/${script}
	${SED} -e "s,^BIN_DIR=.*\$$,BIN_DIR=${SML_BINDIR}," \
	       -e "s,^exec,CM_PATHCONFIG=${SML_LIBDIR}/pathconfig exec," \
		${WRKDIR}/bin/${script} > ${SML_BINDIR}/${script}
	${CHMOD} ${BINMODE} ${SML_BINDIR}/${script}
.endfor
	(cd ${PREFIX}/bin && ${LN} -sf ${SML_BINDIR}/* .)

.include "../../mk/bsd.pkg.mk"
