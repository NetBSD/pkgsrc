# $NetBSD: Makefile,v 1.19 2020/03/22 13:24:00 rillig Exp $
#

DISTNAME=		libtai-0.60
PKGREVISION=		8
CATEGORIES=		devel
MASTER_SITES=		http://cr.yp.to/libtai/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/libtai.html
COMMENT=		Library for storing and manipulating dates and times
LICENSE=		public-domain

CONFLICTS=		libowfat<0.32nb1

DJB_RESTRICTED=		NO
DJB_ERRNO_HACK=		no

EGDIR=			share/examples/${PKGBASE}

SUBST_FILES.djbware+=	leapsecs_read.c

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	leapsecs.3 leapsecs_read.c
SUBST_VARS.paths=	PKG_SYSCONFDIR

INSTALLATION_DIRS=	bin include lib ${EGDIR}
INSTALLATION_DIRS+=	${PKGMANDIR}/man3

post-build:
	cd ${WRKSRC} && ./leapsecs < leapsecs.txt > leapsecs.dat

do-install:
	set -e; cd ${WRKSRC};						\
	for f in *.3; do						\
		${INSTALL_MAN} "$${f}" ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3; \
	done;								\
	for f in easter nowutc leapsecs yearcal; do			\
		${INSTALL_PROGRAM} "$${f}" ${DESTDIR}${PREFIX}/bin;	\
	done;								\
	for f in *.h; do						\
		${INSTALL_DATA} "$${f}" ${DESTDIR}${PREFIX}/include;	\
	done;								\
	for f in libtai.a; do						\
		${INSTALL_DATA} "$${f}" ${DESTDIR}${PREFIX}/lib;		\
	done;								\
	for f in leapsecs.dat leapsecs.txt; do				\
		${INSTALL_DATA} "$${f}" ${DESTDIR}${PREFIX}/${EGDIR};	\
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
