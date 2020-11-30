# $NetBSD: Makefile,v 1.21 2020/11/30 13:42:04 schmonz Exp $
#

DISTNAME=		qmailanalog-0.70
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/qmailanalog.html
COMMENT=		Collection of tools to help analyze qmail's activity
LICENSE=		djb-nonlicense

SUBST_CLASSES+=		djberrno

SUBST_CLASSES+=		pkgmandir
SUBST_STAGE.pkgmandir=	pre-configure
SUBST_FILES.pkgmandir=	hier.c
SUBST_VARS.pkgmandir=	PKGMANDIR

INSTALLATION_DIRS=	share/doc

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
