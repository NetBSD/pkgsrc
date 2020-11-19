# $NetBSD: Makefile,v 1.24 2020/11/19 09:35:40 schmonz Exp $
#

DISTNAME=		safecat-1.13
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://jeenyus.net/~budney/linux/software/safecat/

MAINTAINER=		schmonz@NetBSD.org
#HOMEPAGE=		http://www.jeenyus.net/linux/software/safecat.html
COMMENT=		Write data safely to a maildir

MAKE_JOBS_SAFE=		no

DJB_BUILD_TARGETS+=	install instcheck
DJB_CONFIG_HOME=	conf-root

SUBST_CLASSES+=		pkgmandir
SUBST_STAGE.pkgmandir=	pre-configure
SUBST_FILES.pkgmandir=	hier.c
SUBST_VARS.pkgmandir=	PKGMANDIR

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
