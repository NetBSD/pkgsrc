# $NetBSD: Makefile,v 1.6 2005/03/23 00:51:10 schmonz Exp $
#

DISTNAME=		safecat-1.12
CATEGORIES=		mail
MASTER_SITES=		http://pobox.com/~lbudney/linux/software/safecat/

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://pobox.com/~lbudney/linux/software/safecat.html
COMMENT=		Write data safely to a maildir

USE_BUILDLINK3=		yes

DJB_RESTRICTED=		NO
DJB_BUILD_TARGETS=	install instcheck
DJB_CONFIG_HOME=	conf-root

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
