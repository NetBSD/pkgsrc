# $NetBSD: Makefile,v 1.15 2006/01/05 02:57:10 schmonz Exp $
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

USE_TOOLS+=		nroff

DJB_BUILD_TARGETS=	install instcheck

DJB_RESTRICTED=		YES

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
