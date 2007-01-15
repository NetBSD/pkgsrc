# $NetBSD: Makefile,v 1.11 2007/01/15 11:01:24 schmonz Exp $
#

DISTNAME=		safecat-1.13
CATEGORIES=		mail
MASTER_SITES=		http://jeenyus.net/~budney/linux/software/safecat/

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://jeenyus.net/~budney/linux/software/safecat.html
COMMENT=		Write data safely to a maildir

USE_TOOLS+=		nroff

DJB_RESTRICTED=		NO
DJB_BUILD_TARGETS=	install instcheck
DJB_CONFIG_HOME=	conf-root

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
