# $NetBSD: Makefile,v 1.12 2003/07/17 21:46:33 grant Exp $

DISTNAME=	mush-7.2.5
PKGNAME=	mush-7.2.6.b4.pl1
WRKSRC=		${WRKDIR}
CATEGORIES=	mail
MASTER_SITES=	ftp://cse.ogi.edu/pub/mush/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	ftp://cse.ogi.edu/pub/mush/CONTRIB/
PATCH_DIST_ARGS=	-s -d ${WRKDIR} -E -p1
PATCHFILES=	patch-7.2.6-alpha-1 \
		patch-7.2.6-alpha-2 \
		patch-7.2.6-alpha-3 \
		patch-7.2.6-beta-1 \
		patch-7.2.6-beta-2 \
		patch-7.2.6-beta-3 \
		patch-7.2.6-beta-4

MAINTAINER=	christos@NetBSD.org
COMMENT=	text-based mail client

LICENSE=	mush-license
RESTRICTED=		"Can't sell the code as part of anything"
NO_SRC_ON_CDROM=	${RESTRICTED}

DIST_SUBDIR=	mush

pre-configure:
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/config.h-dist > ${WRKSRC}/config.h
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/makefile.${LOWER_OPSYS} > ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
