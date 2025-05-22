# $NetBSD: Makefile,v 1.22 2025/05/22 04:51:29 schmonz Exp $

DISTNAME=		qmailanalog-0.70
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/qmailanalog.html
COMMENT=		Collection of tools to help analyze qmail's activity
LICENSE=		djb-nonlicense

DJB_ERRNO_FIXUP=	error.h

SUBST_CLASSES+=		pkgmandir
SUBST_STAGE.pkgmandir=	pre-configure
SUBST_FILES.pkgmandir=	hier.c
SUBST_VARS.pkgmandir=	PKGMANDIR

INSTALLATION_DIRS=	share/doc

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
