# $NetBSD: Makefile,v 1.23 2012/03/12 21:52:07 joerg Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=		${EZMLM_VERS}
PKGREVISION=		2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/ezmlm.html
COMMENT=		Easy-to-use, high-speed mailing list manager for qmail
LICENSE=		public-domain

CONFLICTS=		ezmlm-idx-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DJB_RESTRICTED=		no
DJB_CONFIG_CMDS=	${ECHO} ${DESTDIR:Q} > conf-destdir

INSTALLATION_DIRS=	bin man ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/cat1 ${PKGMANDIR}/cat5

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
