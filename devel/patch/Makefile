# $NetBSD: Makefile,v 1.1.1.1 1999/09/18 15:27:09 kim Exp $
#

DISTNAME=	patch-2.5.4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=patch/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/patch/patch.html

NO_PATCH=	yes
GNU_CONFIGURE=	yes

.if exists(/usr/bin/patch)
IGNORE=		"is part of your NetBSD distribution"
.endif

.include "../../mk/bsd.pkg.mk"
