# $NetBSD: Makefile,v 1.13 2012/03/14 23:15:16 joerg Exp $
#

DISTNAME=		qmailanalog-0.70
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/qmailanalog.html
COMMENT=		Collection of tools to help analyze qmail's activity

PKG_DESTDIR_SUPPORT=	user-destdir

DJB_RESTRICTED=		YES
DJB_CONFIG_PREFIX=	${PREFIX}/qmailanalog
BUILD_TARGETS=		prog install instcheck

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
