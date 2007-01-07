# $NetBSD: Makefile,v 1.19 2007/01/07 09:13:58 rillig Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=		${EZMLM_VERS}
PKGREVISION=		1

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/ezmlm.html
COMMENT=		Easy-to-use, high-speed mailing list manager for qmail

CONFLICTS=		ezmlm-idx-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# We change conf-bin and conf-man from the default "/usr/local"
# and don't provide compatibility symlinks.
DJB_RESTRICTED=		YES

INSTALLATION_DIRS=	bin man ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/cat1 ${PKGMANDIR}/cat5

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
