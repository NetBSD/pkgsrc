# $NetBSD: Makefile,v 1.3 2000/08/21 21:01:30 hubertf Exp $
#

DISTNAME=	patch-2.5.4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=patch/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/patch/patch.html

NO_PATCH=	yes
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/bin/patch) && ${OPSYS} != "SunOS"
IGNORE=		"${PKGNAME} is part of your NetBSD distribution"
.endif

.include "../../mk/bsd.pkg.mk"
