# $NetBSD: Makefile,v 1.4 2000/10/24 19:47:13 hubertf Exp $
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

# Needed for bootstrapping pkgsrc!
.if !exists(${GTAR})
GTAR=		/usr/bin/tar		# Solaris
.endif
