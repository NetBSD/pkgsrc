# $NetBSD: Makefile,v 1.1.1.1 2000/11/28 02:17:00 jtb Exp $

DISTNAME=	fftpack
PKGNAME=	fftpack-4.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/fftpack/ \
		ftp://netlib.no/netlib/fftpack/ \
		ftp://ftp.zib.de/netlib/fftpack/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/fftpack/
DISTFILES=	${SRCS:.f=.f.gz} doc.gz

MAINTAINER=	jtb@netbsd.org

DIST_SUBDIR=	${DISTNAME}
NO_WRKSUBDIR=	YES

USE_LIBTOOL=	YES
UES_FORTRAN=	YES

FOPTS?=		-O2
MAKE_ENV+=	"FFLAGS=${FOPTS}"

SRCS = 	cfftb.f cosqf1.f passb2.f radb2.f radfg.f		\
	sinqi.f cfftb1.f cosqi.f passb3.f radb3.f rfftb.f	\
	sint.f cfftf.f cost.f passb4.f radb4.f rfftb1.f		\
	sint1.f cfftf1.f costi.f passb5.f radb5.f rfftf.f	\
	sinti.f cffti.f ezfft1.f passf.f radbg.f rfftf1.f	\
	test.f cffti1.f ezfftb.f passf2.f radf2.f rffti.f	\
	cosqb.f ezfftf.f passf3.f radf3.f rffti1.f cosqb1.f	\
	ezffti.f passf4.f radf4.f sinqb.f cosqf.f passb.f	\
	passf5.f radf5.f sinqf.f

.include "../../mk/bsd.prefs.mk"

do-extract:
	@${MKDIR} ${WRKDIR}
	@for f in ${SRCS} ; do \
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/$$f.gz > ${WRKSRC}/$$f ; done
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/doc.gz > ${WRKSRC}/doc

post-extract:
	@${SED} -e 's:%%FORTRAN%%:'${FC}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fftpack
	${INSTALL_DATA} ${WRKSRC}/doc ${PREFIX}/share/doc/fftpack

.include "../../mk/bsd.pkg.mk"