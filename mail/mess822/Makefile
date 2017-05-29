# $NetBSD: Makefile,v 1.27 2017/05/29 23:20:54 schmonz Exp $
#

DISTNAME=		mess822-0.58
PKGREVISION=		6
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/mess822.html
COMMENT=		Library for parsing Internet mail messages
LICENSE=		public-domain

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

USE_TOOLS+=		nroff

DJB_RESTRICTED=		no

EGDIR=			${PREFIX}/share/examples/mess822
CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
MAKE_DIRS+=		${PKG_SYSCONFDIR}
CONF_FILES+=		${EGDIR}/leapsecs.dat ${PKG_SYSCONFDIR}/leapsecs.dat

DJB_BUILD_TARGETS=	install instcheck

AUTO_MKDIRS=		yes

SUBST_FILES.djbware+=	cdb_seek.c leapsecs_read.c

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	hier.c
SUBST_SED.paths=	-e 's,@PKGMANDIR@,${PKGMANDIR},g'

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
