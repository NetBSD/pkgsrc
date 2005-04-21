# $NetBSD: Makefile,v 1.1.1.1 2005/04/21 01:00:29 schmonz Exp $
#

DISTNAME=		serialmail-0.75
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/serialmail.html
COMMENT=		Tools for passing mail across serial links

DEPENDS+=               qmail>=1.03nb7:../../mail/qmail

# We change conf-home from the default "/usr/local" and don't
# provide compatibility symlinks. We also patch to install docs
# following hier(7), to set reasonable permissions on standard
# pkgsrc directories, and to avoid overwriting the "setlock" binary
# provided by sysutils/daemontools.
DJB_RESTRICTED=		YES

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
