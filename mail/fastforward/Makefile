# $NetBSD: Makefile,v 1.12 2005/03/23 00:51:09 schmonz Exp $
#

DISTNAME=		fastforward-0.51
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/fastforward.html
COMMENT=		Sendmail-style /etc/aliases support for qmail

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

CONFLICTS+=		postfix-[0-9]* sendmail-[0-9]*

USE_BUILDLINK3=		yes

DJB_BUILD_TARGETS=	install instcheck

DJB_RESTRICTED=		YES

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
