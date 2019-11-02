# $NetBSD: Makefile,v 1.32 2019/11/02 16:25:23 rillig Exp $

DISTNAME=	mush-7.2.5
PKGNAME=	mush-7.2.6.b4.pl1
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	# ftp://cse.ogi.edu/pub/mush/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=		# ftp://cse.ogi.edu/pub/mush/CONTRIB/
PATCH_DIST_ARGS=	-s -d ${WRKDIR} -E -p1
PATCHFILES=		patch-7.2.6-alpha-1 \
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

OPSYSVARS+=			PLAT_MAKEFILE
PLAT_MAKEFILE.DragonFly=	makefile.netbsd
PLAT_MAKEFILE.*=		makefile.${LOWER_OPSYS}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	config.h-dist ${PLAT_MAKEFILE}
SUBST_VARS.paths=	PREFIX
SUBST_SED.paths+=	-e 's,@MANDIR@,${PREFIX}/${PKGMANDIR},g'
SUBST_STAGE.paths=	pre-configure

pre-configure:
	${CP} ${WRKSRC}/config.h-dist ${WRKSRC}/config.h
	${CP} ${WRKSRC}/${PLAT_MAKEFILE} ${WRKSRC}/Makefile

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
