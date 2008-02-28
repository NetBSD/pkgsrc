# $NetBSD: Makefile,v 1.33 2008/02/28 11:58:49 rillig Exp $
#

DISTNAME=	port2pkg-1.11
PKGREVISION=	7
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert from a FreeBSD port to a NetBSD package

DEPENDS+=	pkglint-[0-9]*:../../pkgtools/pkglint

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_TOOLS+=	gtar perl:run
AUTO_MKDIRS=			yes

do-extract:
	cd ${FILESDIR} && cp port2pkg.* ${WRKSRC}

SUBST_CLASSES+=		gtar
SUBST_STAGE.gtar=	pre-configure
SUBST_FILES.gtar=	port2pkg.pl
SUBST_SED.gtar=		-e 's|$${GTAR}|${GTAR}|g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/port2pkg.pl ${PREFIX}/bin/port2pkg
	${INSTALL_MAN} ${WRKSRC}/port2pkg.0 ${PREFIX}/${PKGMANDIR}/cat1
	${INSTALL_MAN} ${WRKSRC}/port2pkg.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
