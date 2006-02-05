# $NetBSD: Makefile,v 1.50 2006/02/05 23:08:50 joerg Exp $

DISTNAME=	pwlib-v1_8_3-src
PKGNAME=	pwlib-1.8.3
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES+=	http://www.voxgratia.org/releases/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/openh323/
COMMENT=	Portable Windows Libary

BROKEN_IN=	pkgsrc-2005Q4

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

WRKSRC=			${WRKDIR}/pwlib
USE_TOOLS+=		gmake tar
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-sasl --disable-openldap
CONFIGURE_ARGS+=	--disable-expat --disable-video --disable-qos
PTHREAD_OPTS+=		require

BUILD_TARGET=		opt
MAKE_ENV+=		PWLIBDIR=${WRKSRC:Q} CC=${CC:Q} CPLUS=${CXX:Q}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	make/unix.mak make/lib.mak make/common.mak make/pwlib.mak
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@LIBTOOL@,${LIBTOOL},g'
SUBST_SED.paths+=	-e 's,@BSD_INSTALL_LIB@,${INSTALL_LIB},g'
SUBST_SED.paths+=	-e 's,@BSD_INSTALL_PROGRAM@,${INSTALL_PROGRAM},g'
SUBST_SED.paths+=	-e 's,@PTHREAD_FLAGS@,${PTHREAD_LDFLAGS} ${PTHREAD_LIBS},g'
SUBST_SED.paths+=	-e 's,@LIBOSSAUDIO@,${LIBOSSAUDIO},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	cd ${WRKDIR}; ${TAR} -xf ${DISTNAME:S/$/-tar/}
	mkdir ${WRKSRC}/share
	${LN} -s ../../pwlib ${WRKSRC}/share/pwlib

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
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
