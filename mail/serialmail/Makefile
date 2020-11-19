# $NetBSD: Makefile,v 1.14 2020/11/19 08:11:18 schmonz Exp $
#

DISTNAME=		serialmail-0.75
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/serialmail.html
COMMENT=		Tools for passing mail across serial links
LICENSE=		djb-nonlicense

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

INSTALLATION_DIRS=	share/doc/${PKGBASE}

SUBST_CLASSES+=		djberrno

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	hier.c
SUBST_VARS.paths=	PKGMANDIR

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
