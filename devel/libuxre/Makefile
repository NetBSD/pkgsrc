# $NetBSD: Makefile,v 1.2 2011/10/09 10:02:48 cheusov Exp $

PKGNAME=	libuxre-${HEIRLOOM_VER}
CATEGORIES=	devel

MAINTAINER=	cheusov@NetBSD.org
COMMENT=	POSIX compatible regular expression library

LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	include/uxre share/doc/${PKGBASE} lib

DOC_FILES=	NOTES COPYING.LGPL
DOC_DIR=	${PREFIX}/share/doc/${PKGBASE}

SRCFILES=	onefile    regfree    regerror    btowc
LOFILES=	onefile.lo regfree.lo regerror.lo btowc.lo

NEED_PRE_BUILD=	0

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

pre-build:
	cd ${WRKSRC} && \
	env ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} -f makefile makefiles

do-build:
	set -e; \
	cd ${WRKSRC}/libuxre; \
	for i in ${SRCFILES}; do \
	   ${LIBTOOL} --mode=compile \
	      ${CC} -o "$${i}".o -c ${CFLAGS} -I. "$${i}".c; \
	done; \
	${LIBTOOL} --mode=link ${CC} -o libuxre.la \
	   -rpath ${PREFIX}/lib -version-info 0:0 ${LOFILES}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/libuxre/libuxre.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libuxre/regex.h ${DESTDIR}${PREFIX}/include/uxre
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/libuxre/"${i}" ${DESTDIR}${DOC_DIR}
.endfor

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
