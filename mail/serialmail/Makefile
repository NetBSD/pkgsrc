# $NetBSD: Makefile,v 1.8 2012/10/08 12:19:31 asau Exp $
#

DISTNAME=		serialmail-0.75
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/serialmail.html
COMMENT=		Tools for passing mail across serial links
LICENSE=		djb-nonlicense

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

INSTALLATION_DIRS=	share/doc/${PKGBASE}

# We change conf-home from the default "/usr/local" and don't
# provide compatibility symlinks. We also apply patches.
DJB_RESTRICTED=		YES

SUBST_FILES.djbware+=	leapsecs_read.c

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
