# $NetBSD: Makefile,v 1.13 1998/09/19 22:25:03 tron Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/18 22:20:02 hoek Exp
#

DISTNAME=       uudeview-0.5.13
PKGNAME=        uulib-0.5.13
CATEGORIES=	converters
MASTER_SITES=	http://www.uni-frankfurt.de/~fp/uudeview/Apps/frank/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.informatik.uni-frankfurt.de/~fp/uudeview/

# "kdesupport-2.1b" included "uu" library.
CONFLICTS=	kdesupport-2.1b

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

ALL_TARGET=	libuu.la

WRKSRC=		${WRKDIR}/${DISTNAME}/uulib

DOCFILES=	HISTORY doc/Makefile doc/README doc/binhex.fig \
		doc/library.ltx doc/structure.fig doc/td-v1.c doc/td-v2.c \
		doc/td-v3.c doc/test.txt

.include "../../mk/bsd.prefs.mk"

do-install:
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libuu.la ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/uudeview.h ${PREFIX}/include/uu.h
	${SED} -e 's|FUNKYTOKENHERE|${PREFIX}|g' <${FILESDIR}/uulib.3 >${WRKSRC}/uulib.3
	${INSTALL_MAN} ${WRKSRC}/uulib.3 ${PREFIX}/man/man3
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uulib
	@${INSTALL_MAN} ${FILESDIR}/porting.notes ${PREFIX}/share/doc/uulib
.for docfile in ${DOCFILES}
	@${INSTALL_MAN} ${WRKSRC}/../${docfile} ${PREFIX}/share/doc/uulib
.endfor

.include "../../mk/bsd.pkg.mk"
