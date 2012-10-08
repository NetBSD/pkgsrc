# $NetBSD: Makefile,v 1.16 2012/10/08 12:19:30 asau Exp $
#

DISTNAME=		safecat-1.13
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://jeenyus.net/~budney/linux/software/safecat/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jeenyus.net/~budney/linux/software/safecat.html
COMMENT=		Write data safely to a maildir

MAKE_JOBS_SAFE=		no

DJB_RESTRICTED=		NO
BUILD_TARGETS=		install instcheck
DJB_CONFIG_HOME=	conf-root

MAKE_FLAGS+=		DESTDIR=${DESTDIR:Q}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
