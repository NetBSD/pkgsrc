# $NetBSD: Makefile,v 1.14 2010/02/26 10:28:32 wiz Exp $
#

DISTNAME=		safecat-1.13
CATEGORIES=		mail
MASTER_SITES=		http://jeenyus.net/~budney/linux/software/safecat/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jeenyus.net/~budney/linux/software/safecat.html
COMMENT=		Write data safely to a maildir

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		nroff

DJB_RESTRICTED=		NO
DJB_BUILD_TARGETS=	install instcheck
DJB_CONFIG_HOME=	conf-root

MAKE_FLAGS+=		DESTDIR=${DESTDIR:Q}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
