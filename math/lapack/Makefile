# $NetBSD: Makefile,v 1.39 2019/10/05 06:14:05 ryoon Exp $

.include "Makefile.common"

COMMENT=	Linear Algebra PACKage

BUILD_TARGET=	lapacklib

# -j8 fails with some .o file not-found errors.
MAKE_JOBS_SAFE=	no

#FFLAGS+=		-ffloat-store

# With f2c-20090411nb4, libf2c-20090201nb3, we need EXT_ETIME but gcc44-4.4.1nb3
# needs INT_ETIME.  Rather than trying to enumerate all possible fortran compilers,
# just do a test for it.
do-configure:
	@${ECHO_N} "Checking if fortran compiler has etime() as an intrinsic: "
	@cd ${WRKDIR} && ${FC} -o etime_test ${FILESDIR}/etime_test.f >${WRKDIR}/etime_test.log 2>&1; \
	if test $$? -eq 0 ; then \
	${ECHO} "TIMER=INT_ETIME" >> ${WRKSRC}/make.inc ; ${ECHO} "YES" ; else \
	${ECHO} "TIMER=EXT_ETIME" >> ${WRKSRC}/make.inc ; ${ECHO} "NO" ; fi
	@${ECHO} "See ${WRKDIR}/etime_test.log for details on the test"

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/liblapack.la \
		${DESTDIR}${PREFIX}/lib

.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
