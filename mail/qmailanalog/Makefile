# $NetBSD: Makefile,v 1.15 2017/07/26 00:36:44 schmonz Exp $
#

DISTNAME=		qmailanalog-0.70
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/qmailanalog.html
COMMENT=		Collection of tools to help analyze qmail's activity

DJB_RESTRICTED=		YES
DJB_CONFIG_PREFIX=	${PREFIX}/qmailanalog
BUILD_TARGET=		prog install instcheck

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
