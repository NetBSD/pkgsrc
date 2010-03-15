# $NetBSD: Makefile,v 1.12 2010/03/15 17:30:45 schmonz Exp $
#

DISTNAME=		qmailanalog-0.70
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/qmailanalog.html
COMMENT=		Collection of tools to help analyze qmail's activity

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		nroff

DJB_RESTRICTED=		YES
DJB_CONFIG_PREFIX=	${PREFIX}/qmailanalog

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
