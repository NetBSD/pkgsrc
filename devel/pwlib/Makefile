# $NetBSD: Makefile,v 1.13 2002/08/01 05:48:10 jlam Exp $
#

DISTNAME=		pwlib_min_1.1pl17
PKGNAME=		pwlib-1.1pl17
CATEGORIES=		devel
MASTER_SITES=		http://www.openh323.org/bin/
COUNTRY_MIRRORS=	au au2 us1 us2 ru de at cz pl
.for COUNTRY in ${COUNTRY_MIRRORS}
MASTER_SITES+=		ftp://www.${COUNTRY}.openh323.org/bin/
.endfor

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openh323.org/
COMMENT=		Portable Windows Libary

BUILD_DEPENDS=		bison-[0-9]*:../../devel/bison

WRKSRC=			${WRKDIR}/pwlib

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		native

MAKE_ENV+=		PWLIBDIR=${WRKSRC}
MAKE_ENV+=		CC="${CC}"
MAKE_ENV+=		CPLUS="${CXX}"
ALL_TARGET=		opt

do-configure:
	${LN} -sf ${WRKDIR} ${WRKSRC}/share

pre-install:
	${FIND} ${WRKSRC} \( -name CVS -o -name "*.orig" \) -print |	\
		${XARGS} ${RM} -rf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptclib
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptlib/unix/ptlib
	cd ${WRKSRC}/include;						\
	for f in `${FIND} . -type f -print`; do				\
		${INSTALL_DATA} $$f ${PREFIX}/include/`${DIRNAME} $$f`;	\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/pwlib/make
	cd ${WRKSRC}/make;						\
	for f in unix.mak common.mak lib.mak ptlib.mak; do		\
		${INSTALL_DATA} $$f ${PREFIX}/share/pwlib/make;		\
	done

.include "../../mk/pthread.buildlink.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
.  include "../../devel/unproven-pthreads/buildlink.mk"
.endif

.include "../../mk/bsd.pkg.mk"
