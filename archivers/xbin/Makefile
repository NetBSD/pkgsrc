# $NetBSD: Makefile,v 1.12 2004/01/20 12:07:07 agc Exp $
#

DISTNAME=	${PRGNAME}unix
PKGNAME=	${PRGNAME}-2.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://sunsite.unc.edu/pub/packages/TeX/tools/xbin/
DISTFILES=	${DISTNAME}.c ${PRGNAME}.man

MAINTAINER=	rh@NetBSD.org
COMMENT=	Convert mailable BinHex format into binary

RESTRICTED=	"May not be sold without permission"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	# defined

PRGNAME=	xbin
EXTRACT_ONLY=	# empty

post-extract:
.for dfile in ${DISTFILES}
	${CP} ${DISTDIR}/${dfile} ${WRKSRC}
.endfor

do-build:
	cd ${WRKSRC} && \
	${BUILDLINK_CC} ${CFLAGS} -DBSD -o ${PRGNAME} ${DISTNAME}.c -lcompat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PRGNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PRGNAME}.man ${PREFIX}/man/cat1/${PRGNAME}.0

.include "../../mk/bsd.pkg.mk"
