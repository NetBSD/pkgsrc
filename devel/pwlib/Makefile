# $NetBSD: Makefile,v 1.30 2004/10/08 21:02:53 mjl Exp $
#

DISTNAME=		pwlib_1.5.2
PKGNAME=		${DISTNAME:S/_/-/}
# PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://www.openh323.org/bin/
COUNTRY_MIRRORS=	at us1 us2 ru de cz
.for COUNTRY in ${COUNTRY_MIRRORS}
MASTER_SITES+=		ftp://www.${COUNTRY}.openh323.org/bin/
.endfor

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.openh323.org/
COMMENT=		Portable Windows Libary

BUILD_DEPENDS=		bison-[0-9]*:../../devel/bison

WRKSRC=			${WRKDIR}/pwlib
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PTHREAD_OPTS+=		require

MAKE_ENV+=		PWLIBDIR="${WRKSRC}"
MAKE_ENV+=		CC="${CC}"
MAKE_ENV+=		CPLUS="${CXX}"
ALL_TARGET=		opt

FILES_SUBST+=		LIBTOOL="${LIBTOOL}"
FILES_SUBST+=		PTHREADS_PREFIX="${BUILDLINK_PREFIX.pthread}"

post-patch:
	${_PKG_SILENT}cd ${WRKSRC}/make;				\
	for f in unix.mak lib.mak common.mak; do			\
		${SED} ${FILES_SUBST_SED} $$f > $$f.sed;		\
		${MV} -f $$f.sed $$f;						\
	done
	${LN} -sf ${WRKDIR} ${WRKSRC}/share

do-install:
	${_PKG_SILENT}cd ${WRKSRC}/src/ptlib/unix && ${MAKE_ENV} ${GMAKE} install
	${_PKG_SILENT}cd ${WRKSRC}/tools/asnparser && ${MAKE_ENV} ${GMAKE} install
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptclib
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptlib/unix/ptlib
	cd ${WRKSRC}/include;						\
	for f in `${FIND} . -name CVS -prune -o -type f -print | ${GREP} -v 'ptbuildopts'`; do	\
		${INSTALL_DATA} $$f ${PREFIX}/include/`${DIRNAME} $$f`;	\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/pwlib/make
	cd ${WRKSRC}/make;						\
	for f in *.mak; do		\
		${INSTALL_DATA} $$f ${PREFIX}/share/pwlib/make;		\
	done

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
