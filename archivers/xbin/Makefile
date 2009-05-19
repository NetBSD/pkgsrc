# $NetBSD: Makefile,v 1.26 2009/05/19 08:59:01 wiz Exp $
#

DISTNAME=	${PRGNAME}unix
PKGNAME=	${PRGNAME}-2.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://sunsite.unc.edu/pub/packages/TeX/tools/xbin/
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1

post-extract:
.for dfile in ${DISTFILES}
	${CP} ${DISTDIR:Q}/${dfile:Q} ${WRKSRC:Q}
.endfor

do-build:
	cd ${WRKSRC:Q} && \
	${CC} ${CFLAGS} -o ${PRGNAME:Q} ${DISTNAME:Q}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/${PRGNAME:Q} \
		${DESTDIR}${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/${PRGNAME:Q}.man \
		${DESTDIR}${PREFIX:Q}/${PKGMANDIR}/cat1/${PRGNAME:Q}.0

.include "../../mk/bsd.pkg.mk"
