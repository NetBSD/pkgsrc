# $NetBSD: Makefile,v 1.22 2012/03/12 21:49:49 joerg Exp $
#

DISTNAME=		dot-forward-0.71
PKGREVISION=		3
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
