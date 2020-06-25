# $NetBSD: Makefile,v 1.18 2020/06/25 05:42:38 schmonz Exp $
#

DISTNAME=		qmailanalog-0.70
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/qmailanalog.html
COMMENT=		Collection of tools to help analyze qmail's activity

DJB_RESTRICTED=		YES
DJB_CONFIG_PREFIX=	${PREFIX}/qmailanalog

SUBST_CLASSES+=		djberrno

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
