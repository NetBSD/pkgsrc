# $NetBSD: Makefile,v 1.20 2010/03/15 17:29:43 schmonz Exp $
#

DISTNAME=		fastforward-0.51
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/fastforward.html
COMMENT=		Sendmail-style /etc/aliases support for qmail
LICENSE=		public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

CONFLICTS+=		esmtp>=1.2 postfix-[0-9]* sendmail-[0-9]*

USE_TOOLS+=		nroff

DJB_BUILD_TARGETS=	install instcheck

DJB_RESTRICTED=		no

SUBST_FILES.djbware+=	cdb_seek.c

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
