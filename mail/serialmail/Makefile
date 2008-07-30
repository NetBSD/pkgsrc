# $NetBSD: Makefile,v 1.4 2008/07/30 10:54:10 schmonz Exp $
#

DISTNAME=		serialmail-0.75
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/serialmail.html
COMMENT=		Tools for passing mail across serial links

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

USE_TOOLS+=		nroff

# We change conf-home from the default "/usr/local" and don't
# provide compatibility symlinks. We also patch to install docs
# following hier(7), to set reasonable permissions on standard
# pkgsrc directories, and to avoid overwriting the "setlock" binary
# provided by sysutils/daemontools.
DJB_RESTRICTED=		YES

SUBST_FILES.djbware+=	leapsecs_read.c

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
