# $NetBSD: Makefile,v 1.2 1999/09/19 19:56:48 kim Exp $
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
IGNORE=		"is part of your NetBSD distribution"
.endif

.include "../../mk/bsd.pkg.mk"
