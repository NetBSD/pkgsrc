# $NetBSD: Makefile,v 1.62 2008/05/22 11:45:25 wiz Exp $

DISTNAME=	gc-7.1
PKGNAME=	${DISTNAME:S/gc/boehm-gc/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/
COMMENT=	Garbage collection and memory leak detection for C and C++

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-cplusplus
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc
INSTALLATION_DIRS=	${PKGMANDIR}/man3

MAKE_ENV+=		COPTS=${CFLAGS:M*:Q}

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--disable-threads
.endif

.if !empty(EXTRACT_USING:Mpax)
EXTRACT_ELEMENTS=	-u
.endif

.if ${MACHINE_ARCH} == "mipsel"
CFLAGS+=		-D__MIPSEL__
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/gc.3

do-test:
	cd ${WRKSRC} && \
	${RM} -f gctest && ${MAKE_PROGRAM} gctest && ./gctest && \
	${RM} -f test_cpp && ${MAKE_PROGRAM} test_cpp && ./test_cpp 10

.include "../../mk/bsd.pkg.mk"
