# $NetBSD: Makefile,v 1.5 2000/06/24 16:24:36 kim Exp $

DISTNAME=	mush-7.2.5
PKGNAME=	mush-7.2.6.b4.pl1
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

MAINTAINER=	christos@netbsd.org

DIST_SUBDIR=	mush

RESTRICTED=	"Z-Code license"
MIRROR_DISTFILE= no
NO_WRKSUBDIR=	yes

pre-configure:
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/config.h-dist > ${WRKSRC}/config.h
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/makefile.${LOWER_OPSYS} > ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
