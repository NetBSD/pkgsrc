# $NetBSD: Makefile,v 1.12 2012/09/11 23:19:40 asau Exp $
#

DISTNAME=	verifypc-1.6
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Sanity check package dependencies according to pkg-config

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=		YES
WRKSRC=			${WRKDIR}

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	do-configure
SUBST_MESSAGE.vars=	Configuring sources.
SUBST_FILES.vars=	*
SUBST_SED.vars=		-e 's|@MAKE@|${MAKE}|g'
SUBST_SED.vars+=	-e 's|@SH@|${SH}|g'

INSTALLATION_DIRS=	${PKGMANDIR}/man1 bin

do-extract:
	${CP} ${FILESDIR}/verifypc.sh ${WRKSRC}
	${CP} ${FILESDIR}/verifypc.1 ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/verifypc.sh \
		${DESTDIR}${PREFIX}/bin/verifypc
	${INSTALL_MAN} ${WRKSRC}/verifypc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
