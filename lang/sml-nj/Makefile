# $NetBSD: Makefile,v 1.9 2001/04/28 23:59:17 jtb Exp $
# FreeBSD Id: ports/lang/sml-nj/Makefile,v 1.9 1999/08/25 06:35:27 obrien Exp

DISTNAME=	${SML_VERSION}-bin.${BOX}-unix
PKGNAME=	smlnj-${SML_VERSION}
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.research.bell-labs.com/dist/smlnj/working/${SML_VERSION}/ \
		ftp://ftp.diku.dk/pub/smlnj/working/${SML_VERSION}/ \
		ftp://sunsite.doc.ic.ac.uk/computing/programming/languages/ml/smlnj/working/${SML_VERSION}/ \
		ftp://compiler.kaist.ac.kr/pub/sml/working/${SML_VERSION}/
DISTFILES=	${SML_VERSION}-bin.${BOX}-unix.tar.Z ${SML_VERSION}-cm.tar.Z ${SML_VERSION}-cml.tar.Z \
		${SML_VERSION}-config.tar.Z ${SML_VERSION}-eXene.tar.Z \
		${SML_VERSION}-ml-burg.tar.Z ${SML_VERSION}-ml-lex.tar.Z ${SML_VERSION}-ml-yacc.tar.Z \
		${SML_VERSION}-runtime.tar.Z ${SML_VERSION}-smlnj-c.tar.Z \
		${SML_VERSION}-smlnj-lib.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cm.bell-labs.com/cm/cs/what/smlnj/index.html
COMMENT=	Popular functional language from Bell Labs

SML_VERSION=	110.9.1

# sml-nj also supports hppa, sparc, ppc, mlrisc & alpha
# pkg support for those platforms, and say, solaris-x86
# is left as an (easy) exercise for the reader.
ONLY_FOR_PLATFORM=	NetBSD-*-i386 SunOS-*-sparc NetBSD-*-sparc

# Other mirror sites that generally carry only released versions of SML
# 	ftp://rodin.stanford.edu/pub/smlnj/release/
# 	ftp://ftp.cl.cam.ac.uk/MIRRORED/smlnj/release/
# 	ftp://ftp.ntua.gr/pub/lang/smlnj/release/
# Mirror sites that keep files around in gzipped format
# 	ftp://flint.cs.yale.edu/pub/smlnj/working/${SML_VERSION}/

DIST_SUBDIR=	sml-nj
NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	${SML_VERSION}-config.tar.Z
USE_GMAKE=	yes

SML_BASE=	${PREFIX}/lib/sml-nj
SML_LIBDIR=	${SML_BASE}/lib
SML_BINDIR=	${SML_BASE}/bin
SML_SRCDIR=	${SML_BASE}/src
SML_EXES=	ml-burg ml-lex ml-yacc sml

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
# 1. create installation directories
# 2. copy the ./bin directory across
# 3. edit bin/.run_sml to override BIN_DIR
# 4. copy all .stable files in CM/ directories
# 5. find all .cm files reachable from $WRKDIR/lib and copy them across
# 6. copy the aliases in ./lib changing WRKDIR to SML_LIBDIR
# 7. install links to executables in $PREFIX/bin
do-install:
	${INSTALL_DATA_DIR} ${SML_BASE} ${SML_BINDIR} ${SML_LIBDIR}
	${GTAR} -C ${WRKDIR} -cf - bin | ${GTAR} -C ${SML_BASE} -xf -
	${RM} -f ${SML_BINDIR}/.run-sml
	${SED} -e "s,^BIN_DIR=.*\$$,BIN_DIR=${SML_BINDIR}," \
		${WRKDIR}/bin/.run-sml > ${SML_BINDIR}/.run-sml
	${CHMOD} 755 ${SML_BINDIR}/.run-sml
	cd ${WRKDIR} && ${GTAR} -cf - `${FIND} . -name '*.stable' | \
		${GREP} CM` | ${GTAR} -C ${SML_BASE} -xf -
	cd ${WRKDIR} && ${GTAR} -cf - `${SCRIPTDIR}/get-cm ${WRKDIR}` | \
		${GTAR} -C ${SML_BASE} -xf -
	for file in ${WRKDIR}/lib/*; do\
		${SED} -e "s,${WRKDIR},${SML_BASE}," $$file > \
			${SML_LIBDIR}/`${BASENAME} $$file`; \
	done
.for file in ${SML_EXES}
	-${RM} -f ${PREFIX}/bin/${file}
	-${LN} -s ${SML_BINDIR}/${file} ${PREFIX}/bin/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
