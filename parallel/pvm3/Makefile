# $NetBSD: Makefile,v 1.63 2012/09/11 20:36:18 asau Exp $

DISTNAME=	pvm3.4.6
PKGNAME=	pvm-3.4.6
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_NETLIB:=pvm3/}
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
USE_LANGUAGES=		c fortran77
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake m4 csh:run
MAKE_JOBS_SAFE=		no

PVM_ROOT=		${WRKSRC}
MAKE_ENV+=		PVM_ROOT=${WRKSRC:Q}
MAKE_ENV+=		PVM_ARCH=
MAKE_ENV+=		SSH=${PVM_SSH:Q}
MAKE_ENV+=		MKDIR=${MKDIR:Q}
MAKE_ENV+=		PVMLIB_VER=3:4
MAKE_ENV+=		PVM_DIR=${PVM_DIR:Q}
BUILD_TARGET=		all install

REPLACE_CSH=		${WRKSRC}/lib/debugger ${WRKSRC}/lib/debugger2

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

INSTALLATION_DIRS=	${PVM_DIR}/bin/${PVM_ARCH} ${PVM_DIR}/conf \
			${PVM_DIR}/examples ${PVM_DIR}/gexamples \
			${PVM_DIR}/include ${PVM_DIR}/lib/${PVM_ARCH} \
			${PKGMANDIR}/man1 ${PKGMANDIR}/man3

do-install:
.for __tmp__ in libgpvm3.la libpvm3.la libpvmtrc.la libfpvm3.la
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/lib/${PVM_ARCH}/${__tmp__} ${DESTDIR}${PVM_DIR}/lib/${PVM_ARCH}
.endfor
.for __tmp__ in pvm pvmgs
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/lib/${PVM_ARCH}/${__tmp__} ${DESTDIR}${PVM_DIR}/lib/${PVM_ARCH}/
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/lib/${PVM_ARCH}/pvmd3		\
		${DESTDIR}${PVM_DIR}/lib/${PVM_ARCH}
	${LIBTOOL} --mode=finish ${DESTDIR}${PVM_DIR}/lib/${PVM_ARCH}
	for f in `${LS} -1 ${WRKSRC}/lib`; do				\
		if [ -f ${WRKSRC}/lib/$$f ]; then			\
			${INSTALL_SCRIPT} ${WRKSRC}/lib/$$f ${DESTDIR}${PVM_DIR}/lib; \
		fi;							\
	done

	for f in ${WRKSRC}/bin/${PVM_ARCH}/* ; do \
	${ECHO} "Installing $$f" ; \
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} $$f \
		${DESTDIR}${PVM_DIR}/bin/${PVM_ARCH}/ ; done

	${INSTALL_DATA} ${WRKSRC}/conf/${PVM_ARCH}.def ${DESTDIR}${PVM_DIR}/conf
	${INSTALL_DATA} ${WRKSRC}/conf/${PVM_ARCH}.m4 ${DESTDIR}${PVM_DIR}/conf

	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${DESTDIR}${PVM_DIR}/examples
	${INSTALL_DATA} ${WRKSRC}/examples/*.f ${DESTDIR}${PVM_DIR}/examples
	${INSTALL_DATA} ${WRKSRC}/examples/Readme ${DESTDIR}${PVM_DIR}/examples
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile.aimk ${DESTDIR}${PVM_DIR}/examples

	${INSTALL_DATA} ${WRKSRC}/gexamples/*.c ${DESTDIR}${PVM_DIR}/gexamples
	${INSTALL_DATA} ${WRKSRC}/gexamples/*.f ${DESTDIR}${PVM_DIR}/gexamples
	${INSTALL_DATA} ${WRKSRC}/gexamples/Readme ${DESTDIR}${PVM_DIR}/gexamples
	${INSTALL_DATA} ${WRKSRC}/gexamples/Makefile.aimk ${DESTDIR}${PVM_DIR}/gexamples
	${INSTALL_DATA} ${WRKSRC}/gexamples/Makefile ${DESTDIR}${PVM_DIR}/gexamples

	${INSTALL_DATA} ${WRKSRC}/include/* ${DESTDIR}${PVM_DIR}/include

	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/man3/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/PVM.1
	${LN} -s ${PREFIX}/${PKGMANDIR}/man1/pvm_intro.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/PVM.1

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
