# $NetBSD: Makefile,v 1.12 2002/07/04 20:24:40 wiz Exp $
#

DISTNAME=	boot.${BOX}-unix
PKGNAME=	sml-nj-${SML_VERSION}
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.research.bell-labs.com/dist/smlnj/working/${SML_VERSION}/ \
		ftp://flint.cs.yale.edu/pub/smlnj/working/${SML_VERSION}/
DISTFILES=	MLRISC.tgz			\
		boot.${BOX}-unix.tgz		\
		cm.tgz				\
		cml.tgz				\
		compiler.tgz			\
		config.tgz			\
		eXene.tgz			\
		ml-burg.tgz			\
		ml-lex.tgz			\
		ml-yacc.tgz			\
		runtime.tgz			\
		smlnj-lib.tgz			\
		system.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cm.bell-labs.com/cm/cs/what/smlnj/index.html
COMMENT=	Popular functional language from Bell Labs

SML_VERSION=	110.38

# sml-nj also supports hppa, sparc, ppc, mlrisc & alpha
# pkg support for those platforms, and say, solaris-x86
# is left as an (easy) exercise for the reader.
ONLY_FOR_PLATFORM=	NetBSD-*-i386 SunOS-*-sparc NetBSD-*-sparc

# Other mirror sites that generally carry only released versions of SML
# 	ftp://rodin.stanford.edu/pub/smlnj/release/
# 	ftp://ftp.cl.cam.ac.uk/MIRRORED/smlnj/release/
# 	ftp://ftp.ntua.gr/pub/lang/smlnj/release/

DIST_SUBDIR=	sml-nj-${SML_VERSION}
WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	config.tgz
USE_GMAKE=	yes

SML_BASE=	${PREFIX}/lib/sml-nj
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
