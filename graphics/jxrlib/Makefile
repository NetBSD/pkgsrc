# $NetBSD: Makefile,v 1.3 2019/11/25 21:07:18 nros Exp $

DISTNAME=	jxrlib_1_1
PKGNAME=	jxrlib-1.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	# javascript link

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/curasystems/jxrlib
COMMENT=	JPEG XR library
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

WRKSRC=		${WRKDIR}/jxrlib

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=-D_BIG__ENDIAN_
.endif

INSTALLATION_DIRS=	bin lib
INSTALLATION_DIRS+=	include/jxrlib/common/include
INSTALLATION_DIRS+=	include/jxrlib/image/sys
INSTALLATION_DIRS+=	include/jxrlib/image/encode
INSTALLATION_DIRS+=	include/jxrlib/image/decode
INSTALLATION_DIRS+=	include/jxrlib/image/x86
INSTALLATION_DIRS+=	include/jxrgluelib
INSTALLATION_DIRS+=	share/doc/jxrlib

pre-patch:
	dos2unix ${WRKSRC}/Makefile
	find ${WRKSRC} -name '*.c' -print0 | xargs -0 dos2unix
	find ${WRKSRC} -name '*.h' -print0 | xargs -0 dos2unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/JxrEncApp ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/JxrDecApp ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/*.a ${DESTDIR}${PREFIX}/lib
	for dir in common/include image/sys image/encode image/decode image/x86; do \
		${INSTALL_DATA} ${WRKSRC}/$$dir/*.h ${DESTDIR}${PREFIX}/include/jxrlib/$$dir; \
	done
	${INSTALL_DATA} ${WRKSRC}/jxrgluelib/*.h ${DESTDIR}${PREFIX}/include/jxrgluelib
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/jxrlib

.include "../../mk/bsd.pkg.mk"
