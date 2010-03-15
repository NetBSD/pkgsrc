# $NetBSD: Makefile,v 1.21 2010/03/15 17:28:10 schmonz Exp $
#

DISTNAME=		dot-forward-0.71
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/dot-forward.html
COMMENT=		Reads sendmail's .forward files under qmail
LICENSE=		public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

USE_TOOLS+=		nroff

DJB_BUILD_TARGETS=	install instcheck

DJB_RESTRICTED=		no

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
