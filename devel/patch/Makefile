# $NetBSD: Makefile,v 1.5 2001/02/16 14:38:55 wiz Exp $
#

DISTNAME=	patch-2.5.4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=patch/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/patch/patch.html
COMMENT=	Patch files using diff output

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
