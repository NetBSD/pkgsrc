# $NetBSD: Makefile,v 1.25 2013/11/04 15:34:38 christos Exp $

DISTNAME=	mush-7.2.5
PKGNAME=	mush-7.2.6.b4.pl1
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	# ftp://cse.ogi.edu/pub/mush/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	# ftp://cse.ogi.edu/pub/mush/CONTRIB/
PATCH_DIST_ARGS=	-s -d ${WRKDIR} -E -p1
PATCHFILES=	patch-7.2.6-alpha-1 \
		patch-7.2.6-alpha-2 \
		patch-7.2.6-alpha-3 \
		patch-7.2.6-beta-1 \
		patch-7.2.6-beta-2 \
		patch-7.2.6-beta-3 \
		patch-7.2.6-beta-4

MAINTAINER=	christos@NetBSD.org
COMMENT=	Text-based mail client
LICENSE=	mush-license

RESTRICTED=		Unmodified source may be distributed but not sold.
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	mush
BUILD_TARGET=	mush

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/misc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
PLAT_MAKEFILE=	makefile.netbsd
.else
PLAT_MAKEFILE=	makefile.${LOWER_OPSYS}
.endif

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	config.h-dist ${PLAT_MAKEFILE}
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@MANDIR@,${PREFIX}/${PKGMANDIR},g'
SUBST_STAGE.paths=	post-patch

pre-configure:
	${CP} ${WRKSRC}/config.h-dist ${WRKSRC}/config.h
	${CP} ${WRKSRC}/${PLAT_MAKEFILE} ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
