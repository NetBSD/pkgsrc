# $NetBSD: Makefile,v 1.35 2023/12/12 13:58:26 zafer Exp $

DISTNAME=	${PRGNAME}unix
PKGNAME=	${PRGNAME}-2.3
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://www.aydogan.net/distfiles/archivers/
DISTFILES=	${DISTNAME}.c ${PRGNAME}.man

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert mailable BinHex format into binary

RESTRICTED=		May not be sold without permission.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}

PRGNAME=	xbin
EXTRACT_ONLY=	# empty

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
CFLAGS+=		-DBSD
.  if ${OPSYS} != "OpenBSD"
LDFLAGS+=		-lcompat
.  endif
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
