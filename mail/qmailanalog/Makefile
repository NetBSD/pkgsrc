# $NetBSD: Makefile,v 1.19 2020/11/19 08:11:18 schmonz Exp $
#

DISTNAME=		qmailanalog-0.70
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/qmailanalog.html
COMMENT=		Collection of tools to help analyze qmail's activity
LICENSE=		djb-nonlicense

DJB_CONFIG_PREFIX=	${PREFIX}/qmailanalog

SUBST_CLASSES+=		djberrno

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
