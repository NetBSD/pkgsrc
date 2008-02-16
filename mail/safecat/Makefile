# $NetBSD: Makefile,v 1.12 2008/02/16 15:21:40 heinz Exp $
#

DISTNAME=		safecat-1.13
CATEGORIES=		mail
MASTER_SITES=		http://jeenyus.net/~budney/linux/software/safecat/

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://jeenyus.net/~budney/linux/software/safecat.html
COMMENT=		Write data safely to a maildir

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		nroff

DJB_RESTRICTED=		NO
DJB_BUILD_TARGETS=	install instcheck
DJB_CONFIG_HOME=	conf-root

MAKE_FLAGS+=		DESTDIR=${DESTDIR:Q}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
