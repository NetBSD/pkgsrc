# $NetBSD: Makefile,v 1.33 2004/10/09 14:01:03 mjl Exp $
#

DISTNAME=		pwlib-v1_8_2-src
PKGNAME=		${DISTNAME:S/_/./g:S/-src//:S/-v/-/}
# PKGREVISION=		3
EXTRACT_SUFX=	-tar.gz
CATEGORIES=		devel
# MASTER_SITES=  ${MASTER_SITE_SOURCEFORGE:=openh323/}
MASTER_SITES+=	http://www.voxgratia.org/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/openh323/
COMMENT=		Portable Windows Libary

BUILD_DEPENDS=		bison-[0-9]*:../../devel/bison

WRKSRC=			${WRKDIR}/pwlib
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARHS+=	--disable-sasl --disable-openldap --disable-openssl --disable-expat --disable-video --disable-qos
PTHREAD_OPTS+=		require

MAKE_ENV+=		PWLIBDIR="${WRKSRC}" CC="${CC}" CPLUS="${CXX}"
ALL_TARGET=		opt

FILES_SUBST+=		LIBTOOL="${LIBTOOL}"
FILES_SUBST+=		PTHREADS_PREFIX="${BUILDLINK_PREFIX.pthread}"

post-extract:
	cd ${WRKDIR}; ${TAR} -xf ${DISTNAME:S/$/-tar/}

post-patch:
	${_PKG_SILENT}cd ${WRKSRC}/make;				\
	for f in unix.mak lib.mak common.mak; do			\
		${SED} ${FILES_SUBST_SED} $$f > $$f.sed;		\
		${MV} -f $$f.sed $$f;						\
	done
	${LN} -sf ${WRKDIR} ${WRKSRC}/share

do-install:
	${_PKG_SILENT}cd ${WRKSRC}/src/ptlib/unix && ${MAKE_ENV} ${GMAKE} install
	${INSTALL_DATA_DIR} ${PREFIX}/share/pwlib/make
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptclib
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptlib/unix/ptlib
	cd ${WRKSRC}/make;						\
	for f in *.mak; do		\
		${INSTALL_DATA} $$f ${PREFIX}/share/pwlib/make;		\
	done
	${INSTALL_DATA} ${WRKSRC}/version.h ${PREFIX}/include/ptlib
	cd ${WRKSRC};						\
	for f in `${FIND} include -name CVS -prune -o -name wince -prune -o -name msos -prune -o -type f -print`; do	\
		${INSTALL_DATA} $$f ${PREFIX}/$$f;	\
	done

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
