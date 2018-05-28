# $NetBSD: Makefile,v 1.29 2018/05/28 13:02:04 schmonz Exp $
#

DISTNAME=		mess822-0.58
PKGREVISION=		7
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/mess822.html
COMMENT=		Library for parsing Internet mail messages
LICENSE=		public-domain

DEPENDS_LIBTAI+=	libtai>=0.60nb5:../../devel/libtai
DEPENDS+=		${DEPENDS_LIBTAI}
DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

DJB_RESTRICTED=		no

DJB_BUILD_TARGETS=	install instcheck

AUTO_MKDIRS=		yes

SUBST_FILES.djbware+=	cdb_seek.c

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	hier.c
SUBST_VARS.paths=	PKGMANDIR

pre-build:
	cp ${BUILDLINK_DIR}/include/*.h ${WRKSRC}
	cp ${BUILDLINK_DIR}/lib/*.a ${WRKSRC}

.include "../../devel/libtai/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
