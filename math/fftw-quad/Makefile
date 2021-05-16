# $NetBSD: Makefile,v 1.1 2021/05/16 10:14:09 nia Exp $

PKGNAME=	${DISTNAME:S/fftw-/fftw-quad-/1}

COMMENT=	Fast C routines to compute DFTs (quad precision)

FFTW_PRECISION=	quad-precision

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/fftw-wisdom-to-conf
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/fftw-wisdom-to-conf.1
	${RM} -rf ${DESTDIR}${PREFIX}/info ${DESTDIR}${PREFIX}/include

.include "../../math/fftw/Makefile.common"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/libquadmath/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
