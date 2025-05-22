# $NetBSD: Makefile,v 1.16 2025/05/22 04:51:29 schmonz Exp $

DISTNAME=		serialmail-0.75
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/serialmail.html
COMMENT=		Tools for passing mail across serial links
LICENSE=		public-domain

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

INSTALLATION_DIRS=	share/doc/${PKGBASE}

DJB_ERRNO_FIXUP=	error.h

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	hier.c
SUBST_VARS.paths=	PKGMANDIR

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
