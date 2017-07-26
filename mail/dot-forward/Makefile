# $NetBSD: Makefile,v 1.25 2017/07/26 00:39:27 schmonz Exp $
#

DISTNAME=		dot-forward-0.71
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/dot-forward.html
COMMENT=		Reads sendmail's .forward files under qmail
LICENSE=		public-domain

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

BUILD_TARGET=		prog install instcheck

DJB_RESTRICTED=		no

INSTALLATION_DIRS=	${PKGMANDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	hier.c
SUBST_SED.paths=	-e 's,@PKGMANDIR@,${PKGMANDIR},g'

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
