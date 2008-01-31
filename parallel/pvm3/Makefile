# $NetBSD: Makefile,v 1.50 2008/01/31 19:04:09 tnn Exp $

DISTNAME=	pvm3.4.5
PKGNAME=	pvm-3.4.5
PKGREVISION=	3
CATEGORIES=	parallel
MASTER_SITES=	http://www.netlib.org/pvm3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csm.ornl.gov/pvm/pvm_home.html
COMMENT=	Parallel Virtual Machine libraries and environment

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=		PVM_SSH

.if !defined(PVM_SSH)
PKG_FAIL_REASON+=	PVM_SSH must be defined by the pkgsrc user.
.else
.  if ${PVM_SSH:M${LOCALBASE}/*} != ""
DEPENDS+=		{openssh-[0-9]*,ssh{,6}-1.2.27*}:../../security/openssh
.  endif
.endif

WRKSRC=			${WRKDIR}/pvm3
USE_LANGUAGES=		c fortran
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
MAKE_JOBS_SAFE=		no

PVM_ROOT=		${WRKSRC}
MAKE_ENV+=		PVM_ROOT=${WRKSRC:Q}
MAKE_ENV+=		PVM_ARCH=
MAKE_ENV+=		SSH=${PVM_SSH:Q}
MAKE_ENV+=		MKDIR=${MKDIR:Q}
MAKE_ENV+=		PVMLIB_VER=3:4
MAKE_ENV+=		PVM_DIR=${PVM_DIR:Q}
BUILD_TARGET=		all install

# Set PVM_ARCH to the correct value for this machine platform.
.include "arch.mk"

PVM_DIR=		${PREFIX}/pvm3
BUILDLINK_PASSTHRU_RPATHDIRS+=	${PVM_DIR}/lib/${PVM_ARCH}

post-extract:
	${CP} ${FILESDIR}/DRAGONFLY.m4 ${FILESDIR}/DRAGONFLY.def ${WRKSRC}/conf

post-build:
	${CP} ${WRKSRC}/examples/${PVM_ARCH}/.libs/* \
		${WRKSRC}/bin/${PVM_ARCH}/.libs
	-${CP} ${WRKSRC}/gexamples/${PVM_ARCH}/.libs/* \
		${WRKSRC}/bin/${PVM_ARCH}/.libs

# avoid installing this file
pre-install:
	${RM} -f ${WRKSRC}/lib/pvmgetarch.orig
	${RM} -f ${WRKSRC}/man/man1/pvm_intro.1.orig

do-install:
	${INSTALL_PROGRAM_DIR} ${PVM_DIR}/lib/${PVM_ARCH}
.for __tmp__ in libgpvm3.la libpvm3.la libpvmtrc.la libfpvm3.la
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/lib/${PVM_ARCH}/${__tmp__} ${PVM_DIR}/lib/${PVM_ARCH}
.endfor
.for __tmp__ in pvm pvmgs
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/lib/${PVM_ARCH}/${__tmp__} ${PVM_DIR}/lib/${PVM_ARCH}/
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/lib/${PVM_ARCH}/pvmd3		\
		${PVM_DIR}/lib/${PVM_ARCH}
	${LIBTOOL} --mode=finish ${PVM_DIR}/lib/${PVM_ARCH}
	for f in `${LS} -1 ${WRKSRC}/lib`; do				\
		if [ -f ${WRKSRC}/lib/$$f ]; then			\
			${INSTALL_SCRIPT} ${WRKSRC}/lib/$$f ${PVM_DIR}/lib; \
		fi;							\
	done

	${INSTALL_PROGRAM_DIR} ${PVM_DIR}/bin/${PVM_ARCH}
	for f in ${WRKSRC}/bin/${PVM_ARCH}/* ; do \
	${ECHO} "Installing $$f" ; \
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} $$f \
		${PVM_DIR}/bin/${PVM_ARCH}/ ; done

	${INSTALL_DATA_DIR} ${PVM_DIR}/conf
	${INSTALL_DATA} ${WRKSRC}/conf/${PVM_ARCH}.def ${PVM_DIR}/conf
	${INSTALL_DATA} ${WRKSRC}/conf/${PVM_ARCH}.m4 ${PVM_DIR}/conf

	${INSTALL_DATA_DIR} ${PVM_DIR}/examples
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${PVM_DIR}/examples
	${INSTALL_DATA} ${WRKSRC}/examples/*.f ${PVM_DIR}/examples
	${INSTALL_DATA} ${WRKSRC}/examples/Readme ${PVM_DIR}/examples
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile.aimk ${PVM_DIR}/examples

	${INSTALL_DATA_DIR} ${PVM_DIR}/gexamples
	${INSTALL_DATA} ${WRKSRC}/gexamples/*.c ${PVM_DIR}/gexamples
	${INSTALL_DATA} ${WRKSRC}/gexamples/*.f ${PVM_DIR}/gexamples
	${INSTALL_DATA} ${WRKSRC}/gexamples/Readme ${PVM_DIR}/gexamples
	${INSTALL_DATA} ${WRKSRC}/gexamples/Makefile.aimk ${PVM_DIR}/gexamples
	${INSTALL_DATA} ${WRKSRC}/gexamples/Makefile ${PVM_DIR}/gexamples

	${INSTALL_DATA_DIR} ${PVM_DIR}/include
	${INSTALL_DATA} ${WRKSRC}/include/* ${PVM_DIR}/include

	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/man3/* ${PREFIX}/${PKGMANDIR}/man3
	${RM} ${PREFIX}/${PKGMANDIR}/man1/PVM.1
	${LN} -s ${PREFIX}/${PKGMANDIR}/man1/pvm_intro.1 ${PREFIX}/${PKGMANDIR}/man1/PVM.1

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
