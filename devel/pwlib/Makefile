# $NetBSD: Makefile,v 1.42 2005/05/16 01:32:23 jlam Exp $

DISTNAME=	pwlib-v1_8_3-src
PKGNAME=	pwlib-1.8.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES+=	http://www.voxgratia.org/releases/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/openh323/
COMMENT=	Portable Windows Libary

BUILD_DEPENDS=		bison-[0-9]*:../../devel/bison

WRKSRC=			${WRKDIR}/pwlib
USE_GNU_TOOLS+=		make
PKGSRC_USE_TOOLS+=	tar
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-sasl --disable-openldap
CONFIGURE_ARGS+=	--disable-expat --disable-video --disable-qos
PTHREAD_OPTS+=		require

BUILD_TARGET=		opt
MAKE_ENV+=		PWLIBDIR="${WRKSRC}" CC="${CC}" CPLUS="${CXX}"

FILES_SUBST+=		LIBTOOL="${LIBTOOL}"
FILES_SUBST+=		PTHREADS_PREFIX="${BUILDLINK_PREFIX.pthread}"

post-extract:
	cd ${WRKDIR}; ${TAR} -xf ${DISTNAME:S/$/-tar/}

post-patch:
	${_PKG_SILENT}cd ${WRKSRC}/make;				\
	for f in unix.mak lib.mak common.mak; do			\
		${SED} ${FILES_SUBST_SED} $$f > $$f.sed;		\
		${MV} -f $$f.sed $$f;					\
	done
	${LN} -sf ${WRKDIR} ${WRKSRC}/share

do-install:
	cd ${WRKSRC}/src/ptlib/unix && ${MAKE_ENV} ${GMAKE} install
	${INSTALL_DATA_DIR} ${PREFIX}/share/pwlib/make
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptclib
	${INSTALL_DATA_DIR} ${PREFIX}/include/ptlib/unix/ptlib
	cd ${WRKSRC}/make; ${INSTALL_SCRIPT} ptlib-config ${PREFIX}/bin; \
	for f in *.mak; do		\
		${INSTALL_DATA} $$f ${PREFIX}/share/pwlib/make; \
	done
	${INSTALL_DATA} ${WRKSRC}/version.h ${PREFIX}/include/ptlib
	cd ${WRKSRC}; \
	for f in `${FIND} include -name CVS -prune -o -name wince -prune -o -name msos -prune -o -type f -print`; do	\
		${INSTALL_DATA} $$f ${PREFIX}/$$f;	\
	done

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
