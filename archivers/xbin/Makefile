# $NetBSD: Makefile,v 1.28 2012/03/04 19:50:56 joerg Exp $
#

DISTNAME=	${PRGNAME}unix
PKGNAME=	${PRGNAME}-2.3
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://sunsite.bilkent.edu.tr/pub/tex/ctan/tools/xbin/
DISTFILES=	${DISTNAME}.c ${PRGNAME}.man

MAINTAINER=	rh@NetBSD.org
COMMENT=	Convert mailable BinHex format into binary
LICENSE=	xbin-license

RESTRICTED=	May not be sold without permission.
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

PRGNAME=	xbin
EXTRACT_ONLY=	# empty

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
CFLAGS+=		-DBSD
LDFLAGS+=		-lcompat
.endif
CFLAGS.Interix+=	-DBSD
CFLAGS.Darwin+=		-DBSD

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
.for dfile in ${DISTFILES}
	${CP} ${DISTDIR}/${dfile} ${WRKSRC}
.endfor

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o ${PRGNAME} ${DISTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PRGNAME} \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PRGNAME}.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PRGNAME}.1

.include "../../mk/bsd.pkg.mk"
