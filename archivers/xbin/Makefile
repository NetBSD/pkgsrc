# $NetBSD: Makefile,v 1.18 2005/01/16 16:57:55 tv Exp $
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

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes

PRGNAME=	xbin
EXTRACT_ONLY=	# empty

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD)
CFLAGS+=		-DBSD
LDFLAGS+=		-lcompat
.endif
CFLAGS.Interix+=	-DBSD

INSTALLATION_DIRS=	bin man/cat1

post-extract:
.for dfile in ${DISTFILES}
	${CP} ${DISTDIR}/${dfile} ${WRKSRC}
.endfor

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o ${PRGNAME} ${DISTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PRGNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PRGNAME}.man ${PREFIX}/man/cat1/${PRGNAME}.0

.include "../../mk/bsd.pkg.mk"
