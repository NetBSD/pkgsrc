# $NetBSD: Makefile,v 1.3 2000/10/10 11:50:42 pooka Exp $
#

DISTNAME=	${PRGNAME}unix
PKGNAME=	${PRGNAME}-2.3
NO_WRKSUBDIR=	YES
CATEGORIES=	archivers
MASTER_SITES=	ftp://sunsite.unc.edu/pub/packages/TeX/tools/xbin/
DISTFILES=	${DISTNAME}.c ${PRGNAME}.man

MAINTAINER=	rh@netbsd.org

PRGNAME=	xbin
EXTRACT_ONLY=	# blank

post-extract:
.for dfile in ${DISTFILES}
	${CP} ${DISTDIR}/${dfile} ${WRKSRC}
.endfor

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -DBSD -o ${PRGNAME} ${DISTNAME}.c -lcompat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PRGNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PRGNAME}.man ${PREFIX}/man/cat1/${PRGNAME}.0

.include "../../mk/bsd.pkg.mk"
