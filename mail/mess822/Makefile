# $NetBSD: Makefile,v 1.39 2026/08/03 13:12:28 wiz Exp $

DISTNAME=		mess822-0.58
PKGREVISION=		8
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/mess822.html
COMMENT=		Library for parsing Internet mail messages
LICENSE=		public-domain

DEPENDS+=		libtai>=0.60nb5:../../devel/libtai
DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

DJB_BUILD_TARGETS=	install instcheck
DJB_ERRNO_FIXUP=	cdb_seek.c error.h
AUTO_MKDIRS=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	hier.c
SUBST_VARS.paths=	PKGMANDIR

MESS822PATCHES=			qmailqueue:${QMAILQUEUE_PATCH}
QMAILQUEUE_PATCH=		mess822-0.58-qmailqueue-20170527.patch
PATCHFILES+=			${QMAILQUEUE_PATCH}
PATCH_DIST_STRIP=		-p0
SITES.${QMAILQUEUE_PATCH}=	https://schmonz.com/qmail/mess822qmailqueue/

BUILD_DEFS+=		MESS822PATCHES

pre-build:
	cp ${BUILDLINK_DIR}/include/*.h ${WRKSRC}
	cp ${BUILDLINK_DIR}/lib/*.a ${WRKSRC}

.include "../../devel/libtai/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
